#include <iostream>
#include <fstream>
#include <sstream>

#include <map>
#include <vector>

#include "Hell.hpp"

static const constexpr auto Directory = "/media/cab/DATA/Projects/SomeEmulator/build-OpcodeExtractor-Desktop-Debug/Output/";

void WriteFile(std::string name, std::string content)
{
    std::string fileName(Directory);
    fileName += name;

    std::ofstream outfile(fileName);

    outfile << content;

    outfile << std::endl;

    outfile.close();
}

template <typename T>
void GenerateHeaders(T opcodes)
{
    for (auto& pair : opcodes)
    {
        std::stringstream outfile;

        outfile << "#pragma once" << std::endl;
        outfile << std::endl;
        outfile << "namespace SixFiveOhTwo::Opcodes::" + pair.first << std::endl;
        outfile << "{" <<std::endl;

        outfile << "\tnamespace _private" << std::endl;
        outfile << "\t{" <<std::endl;
        outfile << "\t\t#include \""+ pair.first + ".impl.inc" +"\"" <<std::endl;
        outfile << "\t}" <<std::endl;
        outfile << std::endl;                

        for (auto& opcode : pair.second)
        {
            outfile << "\tstatic const constexpr auto "+opcode.GetAddressing()+"OpCode = " +std::to_string(opcode.Id) + ";" << std::endl;
            outfile << "\ttemplate <typename Cpu, typename Ram, typename Cycles>" << std::endl;
            outfile << "\tvoid "+opcode.GetAddressing()+"(Cpu& cpu, Ram& ram, Cycles cycles)" << std::endl;
            outfile << "\t{" <<std::endl;
            outfile << std::endl;

            outfile << "\t\t" << opcode.GetAddressingFunction() << std::endl;
            outfile << "\t\tauto value = ram.Read(cpu.Temp);" << std::endl;
            outfile << "\t\t_private::"+opcode.Name+"(cpu, value, cycles);" << std::endl;
            outfile << std::endl;
            outfile << "\t}" <<std::endl;
            outfile << std::endl;
        }

        outfile << "}" << std::endl;

        WriteFile(pair.first + ".hpp", outfile.str());
    }
}

template <typename T>
void GenerateImplementations(T opcodes)
{
    for (auto& pair : opcodes)
    {
        std::stringstream outfile;

        outfile << "template <typename Cpu, typename Value, typename Cycles>" << std::endl;
        outfile << "void "+pair.first+"(Cpu& cpu, Value value, Cycles cycles)" << std::endl;
        outfile << "{" <<std::endl;
        outfile << std::endl;
        outfile << "throw \"Not Implemented: \";" <<std::endl;
        outfile << std::endl;
        outfile << "}" <<std::endl;

        WriteFile(pair.first + ".impl.inc", outfile.str());
    }
}

template <typename T>
void GenerateIncludeFile(T opcodes)
{
    std::string includes;

    includes += "#include <AddressingModes.hpp>\r\n";

    for (auto& opcode : opcodes)
    {
        includes += "#include <Opcodes/Data/" + opcode.first + ".hpp>\r\n";
    }

    WriteFile("include.inc", includes);
}

template <typename T>
void GenerateCases(T opcodes)
{    
    std::string file;

    for (auto& opcode : opcodes)
    {
        std::stringstream cases;

        if (opcode.Id == 0) continue;

        cases << "case ";
        cases.flush();
        cases << std::to_string(opcode.Id);
        cases.flush();
        cases << ": SixFiveOhTwo::Opcodes::";
        cases.flush();
        cases << opcode.Name;
        cases.flush();
        cases << "::";
        cases.flush();
        cases << opcode.GetAddressing();
        cases.flush();
        cases << "(cpu, ram, ";
        cases.flush();
        cases << std::to_string(opcode.Cycles);
        cases.flush();
        cases << "); break;";
        cases.flush();
        cases << std::endl;
        cases.flush();

        auto result = cases.str();
        file.append(result);
    }    

    WriteFile("cases.inc", file);
}

class MyHell :
        public Hell
{
private:
    void MaybeAddToMap(Opcode& opcode)
    {
        for (auto& x : _map[opcode.Name])
        {
            if (x.ReallyEqual(opcode))
            {
                return;
            }
        }

        _map[opcode.Name].push_back(opcode);
    }

    void MaybeAddToUniqueMap(Opcode& opcode)
    {
        for (auto& x : _uniqueMap[opcode.Name])
        {
            if (x.AlmostEqual(opcode))
            {
                return;
            }
        }

        _uniqueMap[opcode.Name].push_back(opcode);
    }

public:
    void Hook(Opcode opcode) final override
    {
        _opcodes.push_back(opcode);

        MaybeAddToMap(opcode);

        MaybeAddToUniqueMap(opcode);
    }

    auto Map() const
    {
        return _map;
    }

    auto UniqueMap() const
    {
        return _uniqueMap;
    }

    auto All() const
    {
        return _opcodes;
    }

private:
    std::map<Name_t, std::vector<Opcode>> _uniqueMap;
    std::map<Name_t, std::vector<Opcode>> _map;
    std::vector<Opcode> _opcodes;
};


int main()
{
    std::string path(Directory);
    system(std::string("mkdir " + path).c_str());

    MyHell h;
    h.DoStuff();

    GenerateCases(h.All());
    GenerateIncludeFile(h.UniqueMap());
    GenerateHeaders(h.Map());
    GenerateImplementations(h.Map());
}
