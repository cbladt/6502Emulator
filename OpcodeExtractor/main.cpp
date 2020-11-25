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

        for (auto& opcode : pair.second)
        {
            outfile << "\ttemplate <typename Cpu, typename Ram, typename Cycles>" << std::endl;
            outfile << "\tvoid "+opcode.GetAddressing()+"(Cpu& cpu, Ram& ram, Cycles cycles)" << std::endl;
            outfile << "\t{" <<std::endl;
            outfile << std::endl;
            outfile << std::endl;
            outfile << "\t}" <<std::endl;
            outfile << std::endl;
        }

        outfile << "}" << std::endl;

        WriteFile(pair.first + ".hpp", outfile.str());
    }
}

template <typename T>
void GenerateIncludeFile(T opcodes)
{
    std::string includes;

    for (auto& opcode : opcodes)
    {
        includes += "#include <Opcodes/" + opcode.first + ".hpp>\r\n";
    }

    WriteFile("include.inc", includes);
}

template <typename T>
void GenerateCases(T opcodes)
{
    std::string cases;

    for (auto& opcode : opcodes)
    {
        cases += "case " + std::to_string(opcode.Id) + ": SixFiveOhTwo::Opcodes::" + opcode.Name + "::" + opcode.GetAddressing() + "(cpu, ram, " + std::to_string(opcode.Cycles) + "); break;\r\n";
    }

    WriteFile("cases.inc", cases);
}

class MyHell :
        public Hell
{
public:
    void Hook(Opcode opcode) final override
    {
        _opcodes.push_back(opcode);

        for (auto& x : _map[opcode.Name])
        {
            if (x == opcode)
            {
                return;
            }
        }

        _map[opcode.Name].push_back(opcode);
    }

    auto Map() const
    {
        return _map;
    }

    auto All() const
    {
        return _opcodes;
    }

private:
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
    GenerateIncludeFile(h.Map());
    GenerateHeaders(h.Map());
}
