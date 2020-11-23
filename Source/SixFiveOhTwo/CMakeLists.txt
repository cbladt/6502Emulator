set(SixFiveOhTwoLib SixFiveOhTwoLib)

set(SixFiveOhTwoSource
    "Cpu.cpp"    
    "Opcodes/NoOperation.hpp"
    #"Tasks/Reset.cpp"
    #"Tasks/Interrupt.cpp"
    #"Tasks/InstructionDecoding.cpp"
)

set(SixFiveOhTwoHeader
    "Cpu.hpp"
    "CpuRegisters.hpp"
    "CpuOpcodes.hpp"
    "OpcodeIdentifier.hpp"
    "Ram.hpp"
    "Opcodes/NoOperation.cpp"
    #"Tasks/Reset.hpp"
    #"Tasks/Interrupt.hpp"
    #"Tasks/InstructionDecoding.hpp"
)

add_library(${SixFiveOhTwoLib} STATIC ${SixFiveOhTwoSource} ${SixFiveOhTwoHeader})

target_include_directories(${SixFiveOhTwoLib} PUBLIC .)

target_link_libraries(${SixFiveOhTwoLib} UtilityLib ClockLib)
