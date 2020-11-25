#pragma once
#include <string>
#include <cstdint>
#include <algorithm>

using Name_t = std::string;
using Id_t = uint8_t;
using Cycles_t = uint8_t;

enum class Addressing_t
{
    Implied,
    Immediate,
    Relative,
    ZeroPage,
    ZeroPage_XOffset,
    ZeroPage_YOffset,
    Absolute,
    Absolute_XOffset,
    Absolute_YOffset,
    Indirect,
    Indirect_XOffset,
    Indirect_YOffset
};

struct Opcode
{
    Name_t Name;
    Id_t Id;
    Cycles_t Cycles;
    Addressing_t Addressing;

    bool ReallyEqual(const Opcode& other)
    {
        return other.Name == Name && other.Addressing == Addressing && other.Cycles == Cycles;
    }

    bool AlmostEqual(const Opcode& other)
    {
        return other.Name == Name && other.Id == Id && other.Addressing == Addressing;
    }

    std::string GetAddressing()
    {
        switch(Addressing)
        {
            case Addressing_t::Implied:             return "Implied";
            case Addressing_t::Immediate:           return "Immediate";
            case Addressing_t::Relative:            return "Relative";
            case Addressing_t::ZeroPage:            return "ZeroPage";
            case Addressing_t::ZeroPage_XOffset:    return "ZeroPageXOffset";
            case Addressing_t::ZeroPage_YOffset:    return "ZeroPageYOffset";
            case Addressing_t::Absolute:            return "Absolute";
            case Addressing_t::Absolute_XOffset:    return "AbsoluteXOffset";
            case Addressing_t::Absolute_YOffset:    return "AbsoluteYOffset";
            case Addressing_t::Indirect:            return "Indirect";
            case Addressing_t::Indirect_XOffset:    return "IndirectXOffset";
            case Addressing_t::Indirect_YOffset:    return "IndirectYOffset";
        }
    }

    std::string GetAddressingFunction()
    {
        switch(Addressing)
        {
            case Addressing_t::Implied:             return "AddressingModes::Implied(cpu, ram);";
            case Addressing_t::Immediate:           return "AddressingModes::Immediate(cpu, ram);";
            case Addressing_t::Relative:            return "AddressingModes::Relative(cpu, ram);";
            case Addressing_t::ZeroPage:            return "AddressingModes::ZeroPage::NoOffset(cpu, ram);";
            case Addressing_t::ZeroPage_XOffset:    return "AddressingModes::ZeroPage::XOffset(cpu, ram);";
            case Addressing_t::ZeroPage_YOffset:    return "AddressingModes::ZeroPage::YOffset(cpu, ram);";
            case Addressing_t::Absolute:            return "AddressingModes::Absolute::NoOffset(cpu, ram);";
            case Addressing_t::Absolute_XOffset:    return "AddressingModes::Absolute::XOffset(cpu, ram);";
            case Addressing_t::Absolute_YOffset:    return "AddressingModes::Absolute::YOffset(cpu, ram);";
            case Addressing_t::Indirect:            return "AddressingModes::Indirect::XOffset(cpu, ram);";
            case Addressing_t::Indirect_XOffset:    return "AddressingModes::Absolute::XOffset(cpu, ram);";
            case Addressing_t::Indirect_YOffset:    return "AddressingModes::Absolute::YOffset(cpu, ram);";
        }
    }
};

class Hell
{
public:
    Hell() :
        _index(0)
    {}

    void DoStuff()
    {
        for (_index = 0; _index < 256; _index++)
        {
            Test(_index);
        }
    }

    virtual void Hook(Opcode opcode) = 0;

private:
    size_t _index;

    template <typename T>
    void RemoveChar(T& input, char c)
    {
        input.erase(remove(input.begin(), input.end(), c), input.end());
    }

    template <typename T>
    void ToUpper(T& input)
    {
        std::transform(input.begin(), input.end(), input.begin(),
                          [](unsigned char c) -> unsigned char { return std::toupper(c); });
    }

    void Print(Name_t name, Addressing_t addr = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        ToUpper(name);

        RemoveChar(name, '_');

        Hook({name, _index, cycles, addr});
    }

    Addressing_t addr_indx()
    {
        return Addressing_t::Indirect_XOffset;
    }

    Addressing_t addr_indy()
    {
        return Addressing_t::Indirect_YOffset;
    }

    Addressing_t addr_zero()
    {
        return Addressing_t::ZeroPage;
    }

    Addressing_t addr_zerox()
    {
        return Addressing_t::ZeroPage_XOffset;
    }

    Addressing_t addr_zeroy()
    {
        return Addressing_t::ZeroPage_YOffset;
    }

    Addressing_t addr_abs()
    {
        return Addressing_t::Absolute;
    }

    Addressing_t addr_absx()
    {
        return Addressing_t::Absolute_XOffset;
    }

    Addressing_t addr_absy()
    {
        return Addressing_t::Absolute_YOffset;
    }

    Addressing_t fetch_op()
    {
        return Addressing_t::Implied;
    }

    Addressing_t load_byte(Addressing_t a)
    {
        return a;
    }

    void brk(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("BRK");
    }

    void ora(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("ORA", i, cycles);
    }

    void asl_mem(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("ASLMEM", i, cycles);
    }

    void php(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("PHP");
    }

    void asl_a(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("ASLA");
    }

    void bpl(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("BPL");
    }

    void clc(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("CLC");
    }

    void jsr(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("JSR");
    }

    void _and(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("AND", i, cycles);
    }

    void bit(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("BIT", i, cycles);
    }

    void rol_mem(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("ROLMEM", i, cycles);
    }

    void plp(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("PLP");
    }

    void rol_a(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("ROLA");
    }

    void bmi(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("BMI");
    }

    void sec(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("SEC");
    }

    void rti(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("RTI");
    }

    void pha(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("PHA");
    }

    void eor(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print("EOR", i, cycles);
    }

    void lsr_mem(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void bvc(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void jmp(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void lsr_a(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void cli(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void rts(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void adc(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void ror_mem(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void pla(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void ror_a(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void jmp_ind(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void bvs(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void sei(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void sta(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void sty(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void stx(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void dey(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void bcc(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void txa(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void txs(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void tsx(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void tya(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void tax(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void ldy(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void lda(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void ldx(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void lay(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void tay(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void bey(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void bcs(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void clv(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void cmp(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void cpy(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void inc(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void dec(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void iny(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void dex(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void cld(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void bne(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void cpx(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void sbc(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void inx(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void nop(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void beq(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void sed(Addressing_t i = Addressing_t::Implied, Cycles_t cycles = 0)
    {
        Print(std::string(__func__), i, cycles);
    }

    void Test(uint8_t x)
    {
        switch(x)
        {
            default:
            {

            }

            case 0x0: brk(); break;
            case 0x1: ora(load_byte(addr_indx()),6); break;
            case 0x5: ora(load_byte(addr_zero()),3); break;
            case 0x6: asl_mem(addr_zero(),5); break;
            case 0x8: php(); break;
            case 0x9: ora(fetch_op(),2); break;
            case 0xA: asl_a(); break;
            case 0xD: ora(load_byte(addr_abs()),4); break;
            case 0xE: asl_mem(addr_abs(),6); break;
            case 0x10: bpl(); break;
            case 0x11: ora(load_byte(addr_indy()),5); break;
            case 0x15: ora(load_byte(addr_zerox()),4); break;
            case 0x16: asl_mem(addr_zerox(),6); break;
            case 0x18: clc(); break;
            case 0x19: ora(load_byte(addr_absy()),4); break;
            case 0x1D: ora(load_byte(addr_absx()),4); break;
            case 0x1E: asl_mem(addr_absx(),7); break;
            case 0x20: jsr(); break;
            case 0x21: _and(load_byte(addr_indx()),6); break;
            case 0x24: bit(addr_zero(),3); break;
            case 0x25: _and(load_byte(addr_zero()),3); break;
            case 0x26: rol_mem(addr_zero(),5); break;
            case 0x28: plp(); break;
            case 0x29: _and(fetch_op(),2); break;
            case 0x2A: rol_a(); break;
            case 0x2C: bit(addr_abs(),4); break;
            case 0x2D: _and(load_byte(addr_abs()),4); break;
            case 0x2E: rol_mem(addr_abs(),6); break;
            case 0x30: bmi(); break;
            case 0x31: _and(load_byte(addr_indy()),5); break;
            case 0x35: _and(load_byte(addr_zerox()),4); break;
            case 0x36: rol_mem(addr_zerox(),6); break;
            case 0x38: sec(); break;
            case 0x39: _and(load_byte(addr_absy()),4); break;
            case 0x3D: _and(load_byte(addr_absx()),4); break;
            case 0x3E: rol_mem(addr_absx(),7); break;
            case 0x40: rti(); break;
            case 0x41: eor(load_byte(addr_indx()),6); break;
            case 0x45: eor(load_byte(addr_zero()),3); break;
            case 0x46: lsr_mem(addr_zero(),5); break;
            case 0x48: pha(); break;
            case 0x49: eor(fetch_op(),2); break;
            case 0x50: bvc(); break;
            case 0x4C: jmp(); break;
            case 0x4D: eor(load_byte(addr_abs()),4); break;
            case 0x4A: lsr_a(); break;
            case 0x4E: lsr_mem(addr_abs(),6); break;
            case 0x51: eor(load_byte(addr_indy()),5); break;
            case 0x55: eor(load_byte(addr_zerox()),4); break;
            case 0x56: lsr_mem(addr_zerox(),6); break;
            case 0x58: cli(); break;
            case 0x59: eor(load_byte(addr_absy()),4); break;
            case 0x5D: eor(load_byte(addr_absx()),4); break;
            case 0x5E: lsr_mem(addr_absx(),7); break;
            case 0x60: rts(); break;
            case 0x61: adc(load_byte(addr_indx()),6); break;
            case 0x65: adc(load_byte(addr_zero()),3); break;
            case 0x66: ror_mem(addr_zero(),5); break;
            case 0x68: pla(); break;
            case 0x69: adc(fetch_op(),2); break;
            case 0x6A: ror_a(); break;
            case 0x6C: jmp_ind(); break;
            case 0x6D: adc(load_byte(addr_abs()),4); break;
            case 0x6E: ror_mem(addr_abs(),6); break;
            case 0x70: bvs(); break;
            case 0x71: adc(load_byte(addr_indy()),5); break;
            case 0x75: adc(load_byte(addr_zerox()),4); break;
            case 0x76: ror_mem(addr_zerox(),6); break;
            case 0x78: sei(); break;
            case 0x79: adc(load_byte(addr_absy()),4); break;
            case 0x7D: adc(load_byte(addr_absx()),4); break;
            case 0x7E: ror_mem(addr_absx(),7); break;
            case 0x81: sta(addr_indx(),6); break;
            case 0x84: sty(addr_zero(),3); break;
            case 0x85: sta(addr_zero(),3); break;
            case 0x86: stx(addr_zero(),3); break;
            case 0x88: dey(); break;
            case 0x8A: txa(); break;
            case 0x8C: sty(addr_abs(),4); break;
            case 0x8D: sta(addr_abs(),4); break;
            case 0x8E: stx(addr_abs(),4); break;
            case 0x90: bcc(); break;
            case 0x91: sta(addr_indy(),6); break;
            case 0x94: sty(addr_zerox(),4); break;
            case 0x95: sta(addr_zerox(),4); break;
            case 0x96: stx(addr_zeroy(),4); break;
            case 0x98: tya(); break;
            case 0x99: sta(addr_absy(),5); break;
            case 0x9A: txs(); break;
            case 0x9D: sta(addr_absx(),5); break;
            case 0xA0: ldy(fetch_op(),2); break;
            case 0xA1: lda(load_byte(addr_indx()),6); break;
            case 0xA2: ldx(fetch_op(),2); break;
            case 0xA4: ldy(load_byte(addr_zero()),3); break;
            case 0xA5: lda(load_byte(addr_zero()),3); break;
            case 0xA6: ldx(load_byte(addr_zero()),3); break;
            case 0xA8: tay(); break;
            case 0xA9: lda(fetch_op(),2); break;
            case 0xAA: tax(); break;
            case 0xAC: ldy(load_byte(addr_abs()),4); break;
            case 0xAD: lda(load_byte(addr_abs()),4); break;
            case 0xAE: ldx(load_byte(addr_abs()),4); break;
            case 0xB0: bcs(); break;
            case 0xB1: lda(load_byte(addr_indy()),5); break;
            case 0xB4: ldy(load_byte(addr_zerox()),3); break;
            case 0xB5: lda(load_byte(addr_zerox()),3); break;
            case 0xB6: ldx(load_byte(addr_zeroy()),3); break;
            case 0xB8: clv(); break;
            case 0xB9: lda(load_byte(addr_absy()),4); break;
            case 0xBA: tsx(); break;
            case 0xBC: ldy(load_byte(addr_absx()),4); break;
            case 0xBD: lda(load_byte(addr_absx()),4); break;
            case 0xBE: ldx(load_byte(addr_absy()),4); break;
            case 0xC0: cpy(fetch_op(),2); break;
            case 0xC1: cmp(load_byte(addr_indx()),6); break;
            case 0xC4: cpy(load_byte(addr_zero()),3); break;
            case 0xC5: cmp(load_byte(addr_zero()),3); break;
            case 0xC6: dec(addr_zero(),5); break;
            case 0xC8: iny(); break;
            case 0xC9: cmp(fetch_op(),2); break;
            case 0xCA: dex(); break;
            case 0xCC: cpy(load_byte(addr_abs()),4); break;
            case 0xCD: cmp(load_byte(addr_abs()),4); break;
            case 0xCE: dec(addr_abs(),6); break;
            case 0xD0: bne(); break;
            case 0xD1: cmp(load_byte(addr_indy()),5); break;
            case 0xD5: cmp(load_byte(addr_zerox()),4); break;
            case 0xD6: dec(addr_zerox(),6); break;
            case 0xD8: cld(); break;
            case 0xD9: cmp(load_byte(addr_absy()),4); break;
            case 0xDD: cmp(load_byte(addr_absx()),4); break;
            case 0xDE: dec(addr_absx(),7); break;
            case 0xE0: cpx(fetch_op(),2); break;
            case 0xE1: sbc(load_byte(addr_indx()),6); break;
            case 0xE4: cpx(load_byte(addr_zero()),3); break;
            case 0xE5: sbc(load_byte(addr_zero()),3); break;
            case 0xE6: inc(addr_zero(),5); break;
            case 0xE8: inx(); break;
            case 0xE9: sbc(fetch_op(),2); break;
            case 0xEA: nop(); break;
            case 0xEC: cpx(load_byte(addr_abs()),4); break;
            case 0xED: sbc(load_byte(addr_abs()),4); break;
            case 0xEE: inc(addr_abs(),6); break;
            case 0xF0: beq(); break;
            case 0xF1: sbc(load_byte(addr_indy()),5); break;
            case 0xF5: sbc(load_byte(addr_zerox()),4); break;
            case 0xF6: inc(addr_zerox(),6); break;
            case 0xF8: sed(); break;
            case 0xF9: sbc(load_byte(addr_absy()),4); break;
            case 0xFD: sbc(load_byte(addr_absx()),4); break;
            case 0xFE: inc(addr_absx(),7); break;
        }
    }
};
