"""io:reg generator"""

import sys
import swd.svd


class RegGeneratorError(Exception):
    pass


def generate_bits(register):
    print("        struct Bits {")
    current_offset = 0
    for field in register.fields:
        if field.offset > current_offset:
            offset = field.offset - current_offset
            print(f"            uint32_t : {offset};")
        elif field.offset < current_offset:
            raise RegGeneratorError("REPEATING BITS")
        current_offset = field.offset + field.width
        prefix = ''
        if field.allow_read and not field.allow_write:
            prefix = 'const '
        print(f"            {prefix}uint32_t {field.name} : {field.width};  // {field.description}")
        for enumerated_value in field.enumerated_values:
            print(f"            // {enumerated_value}")
    if current_offset < 32:
        print(f"            uint32_t : {32 - current_offset};")
    elif current_offset > 32:
        raise RegGeneratorError("Too many bits in register")
    print("        };")


def generate_registers_definitions(peripheral):
    for register in peripheral.registers:
        register_class_name = register.name.capitalize()
        print(f"    /** {register.description}")
        print("     */")
        print(f"    struct {register_class_name} {{")
        print(f"        {register_class_name}(const uint32_t raw=0) {{ r = raw; }}")
        print()
        generate_bits(register)
        print()
        print("        union {")
        print("            uint32_t r;")
        print("            Bits b;")
        print("        };")
        print("    };")
        print()


def generate_registers(peripheral):
    registers = []
    current_offset = 0
    for register in peripheral.registers:
        offset = register.offset - current_offset
        if offset % 4 != 0:
            raise RegGeneratorError("wrong registers alignment")
        offset //= 4
        if offset == 0:
            registers.append(register)
        elif offset > 0:
            registers.append(offset)
            registers.append(register)
        elif offset < 0:
            if isinstance(registers[offset], int):
                raise RegGeneratorError("Inconsistent registers definition")
            if isinstance(registers[offset], swd.svd.Register):
                registers[offset] = [registers[offset]]
            if isinstance(registers[offset], list):
                registers[offset].append(register)
            else:
                raise RegGeneratorError("Unexpected error")
        current_offset = register.offset + 4
    res_counter = 0
    for register in registers:
        # print(register)
        if isinstance(register, int):
            if register == 1:
                print(f"    uint32_t _res{res_counter:02d}")
            elif register > 1:
                print(f"    uint32_t _res{res_counter:02d}[{(register)}]")
            else:
                raise RegGeneratorError("Unexpected error")
            res_counter += 1
        elif isinstance(register, swd.svd.Register):
            register_class_name = register.name.capitalize()
            print(f"    volatile {register_class_name} {register.name};  // {register.description}")
        elif isinstance(register, list):
            index = 1
            # print(str(registers))
            while len({reg.name[:index] for reg in register}) == 1:
                index += 1
            index -= 1
            print("    union {")
            common_name = register[0].name[:index].upper()

            for union_register in register:
                register_class_name = union_register.name.capitalize()
                print(f"        volatile {register_class_name} {union_register.name.removeprefix(common_name)};  // {union_register.description}")
            if index > 0:
                print(f"    }} {common_name.rstrip('_')};")
            else:
                print("    } FIXME;")


def generate_peripheral(peripheral):
    peripheral_class_name = peripheral.name.capitalize()
    print("/**")
    print(" * Peripheral Definition File")
    print(" *")
    print(f" * {peripheral.name} - {peripheral.description}")
    print(" */")
    print()
    print("#pragma once")
    print()
    print("#include <cstdint>")
    print("#include <cstddef>")
    print()
    print("namespace io {")
    print()
    print(f"/** {peripheral.description}")
    print(" */")
    print(f"struct {peripheral_class_name} {{")
    generate_registers_definitions(peripheral)
    generate_registers(peripheral)
    print("};")
    print()
    print("namespace base {")
    print()
    print(f"static const size_t {peripheral.name} = 0x{peripheral.base_address:8x};")
    print()
    print("}")
    print()
    print(f"static {peripheral_class_name} &{peripheral.name} = *reinterpret_cast<{peripheral_class_name} *>(base::{peripheral.name});")
    print()
    print("}")


def generate_handlers(svd):
    print("/**")
    print(" * Handlers Setup File")
    print(" */")
    print('#include "io/lib/io_def.hpp"')
    print()
    print('// Undefined handler is pointing to this function, this stop MCU.')
    print('// This function name must by not mangled, so must be C,')
    print('// because alias("..") is working only with C code')
    print('extern "C" void __stop_mcu() { while (true); }')
    print()
    print('// These handler are with attribute "weak" and can be overwritten')
    print('// by non-week function, default is __stop_mcu() function')
    for interrupt in svd.interrupts:
        print(f'__attribute__((weak, alias("__stop_mcu"))) void {interrupt.name}_handler();')
    print()
    print("// Dummy handler (for unused vectors)")
    print("extern void DUMMY_handler();")
    print()
    print('__attribute__((section(".vectors_mcu"), used)) ptr_func_t __isr_vectors_mcu[] = {')
    last_vector = -1
    for interrupt in svd.interrupts:
        while last_vector + 1 < interrupt.vector:
            last_vector += 1
            print("    DUMMY_handler,")
        last_vector = interrupt.vector
        print(f'    {interrupt.name}_handler,  // {interrupt.vector}')
    print("};")


def main(svd_file, peripheral_name=None):
    svd = swd.svd.Svd()
    svd.parse_svd(svd_file)
    svd.validate()
    if not peripheral_name:
        for peripheral in svd.peripherals:
            print(f"0x{peripheral.base_address:08x} : {peripheral.name}")
    elif peripheral_name == 'handlers':
        generate_handlers(svd)
    else:
        for peripheral in svd.peripherals:
            if peripheral_name == peripheral.name:
                generate_peripheral(peripheral)
                break


if __name__ == "__main__":
    if len(sys.argv) == 2:
        main(sys.argv[1])
    elif len(sys.argv) == 3:
        main(sys.argv[1], sys.argv[2])
    else:
        print(f'Usage: {sys.argv[0]} path/to/file.svd [PERIPHERAL_NAME|handlers]')
