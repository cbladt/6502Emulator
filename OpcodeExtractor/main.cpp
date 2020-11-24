#include <iostream>
#include <fstream>

#include <string>
#include <algorithm>
#include <vector>
#include <map>

using Params = std::vector<std::pair<std::string, uint8_t>>;
using Ops = std::map<std::string, Params>;

namespace
{
    uint8_t N = 0;
    Ops X;
    std::vector<std::string> Y;
}


void Switch(std::string s, std::string a = "", uint8_t cycles = 0)
{    
    std::cout << "case " + std::to_string(N) + ": SixFiveOhTwo::Opcodes::" + s + "::"+a+"(cpu, ram, " + std::to_string(cycles) + "); break;" << std::endl;

    //std::cout << "case " << std::to_string(N) << ": " << s << "::Execute(cpu, ram, "<< std::to_string(cycles) << a << "); break;" << std::endl;
}

void Files(std::string s, std::string addressing = "", uint8_t cycles = 0)
{
    for (auto& y : Y)
    {
        if (y == s)
        {
            return;
        }
    }

    Y.push_back(s);
}

void Object(std::string s, std::string addressing = "", uint8_t cycles = 0)
{
    auto params = std::make_pair(addressing, cycles);

    for (auto& p : X[s])
    {
        if (p == params)
        {
            return;
        }
    }

    X[s].push_back(std::make_pair(addressing, cycles));
}

void Print(std::string s, std::string addressing = "", uint8_t cycles = 0)
{
    std::transform(s.begin(), s.end(), s.begin(),
                      [](unsigned char c) -> unsigned char { return std::toupper(c); });

    s.erase(remove(s.begin(), s.end(), '_'), s.end());

    std::string a(addressing.empty() ? "Implied" : addressing);

    Object(s, a, cycles);
}

std::string addr_indx()
{
    return "IndirectOffsetX";
}

std::string addr_indy()
{
    return "IndirectOffsetY";
}

std::string addr_zero()
{
    return "Zero";
}

std::string addr_zerox()
{
    return "ZeroOffsetX";
}

std::string addr_zeroy()
{
    return "ZeroOffsetY";
}

std::string addr_abs()
{
    return "Absolute";
}

std::string addr_absy()
{
    return "AbsoluteOffsetY";
}

std::string addr_absx()
{
    return "AbsoluteOffsetX";
}

std::string fetch_op()
{
    return "Implied";
}

std::string load_byte(std::string i)
{
    return i;
}

void brk()
{
    Print("BRK");
}

void ora(std::string i, uint8_t cycles)
{
    Print("ORA", i, cycles);
}

void asl_mem(std::string i, uint8_t cycles)
{
    Print("ASLMEM", i, cycles);
}

void php()
{
    Print("PHP");
}

void asl_a()
{
    Print("ASLA");
}

void bpl()
{
    Print("BPL");
}

void clc()
{
    Print("CLC");
}

void jsr()
{
    Print("JSR");
}

void _and(std::string i, uint8_t cycles)
{
    Print("AND", i, cycles);
}

void bit(std::string i, uint8_t cycles)
{
    Print("BIT", i, cycles);
}

void rol_mem(std::string i, uint8_t cycles)
{
    Print("ROLMEM", i, cycles);
}

void plp()
{
    Print("PLP");
}

void rol_a()
{
    Print("ROLA");
}

void bmi()
{
    Print("BMI");
}

void sec()
{
    Print("SEC");
}

void rti()
{
    Print("RTI");
}

void pha()
{
    Print("PHA");
}

void eor(std::string i = "", uint8_t cycles = 0)
{
    Print("EOR", i, cycles);
}

void lsr_mem(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void bvc(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void jmp(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void lsr_a(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void cli(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void rts(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void adc(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void ror_mem(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void pla(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void ror_a(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void jmp_ind(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void bvs(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void sei(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void sta(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void sty(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void stx(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void dey(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void bcc(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void txa(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void txs(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void tsx(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void tya(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void tax(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void ldy(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void lda(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void ldx(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void lay(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void tay(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void bey(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void bcs(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void clv(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void cmp(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void cpy(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void inc(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void dec(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void iny(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void dex(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void cld(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void bne(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void cpx(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void sbc(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void inx(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void nop(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void beq(std::string i = "", uint8_t cycles = 0)
{
    Print(std::string(__func__), i, cycles);
}

void sed(std::string i = "", uint8_t cycles = 0)
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

/*#pragma once

namespace SixFiveOhTwo::Opcodes::NoOperation
{
    template <typename Cpu_t>
    void Execute(Cpu_t& cpu)
    {
        cpu.CyclesLeft += 2;
    }
}*/


int main()
{
    for (N = 0; N < 255; N++)
    {
        Test(N);
    }

    for (auto& y : Y)
    {
        std::cout << "#include <Opcodes/"+y+".hpp>" << std::endl;
    }

    for (auto& op : X)
    {
        std::ofstream outfile(op.first + ".hpp");

        outfile << "#pragma once" << std::endl;
        outfile << std::endl;
        outfile << "namespace SixFiveOhTwo::Opcodes::" + op.first << std::endl;
        outfile << "{" <<std::endl;

        for (auto& pair : op.second)
        {
            outfile << "\ttemplate <typename Cpu, typename Ram, typename Cycles>" << std::endl;
            outfile << "\tvoid "+pair.first+"(Cpu& cpu, Ram& ram, Cycles cycles)" << std::endl;
            outfile << "\t{" <<std::endl;
            outfile << std::endl;
            outfile << std::endl;
            outfile << "\t}" <<std::endl;
            outfile << std::endl;
        }

        outfile << "}" << std::endl;
    }
}
