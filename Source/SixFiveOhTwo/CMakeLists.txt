set(SixFiveOhTwoLib SixFiveOhTwoLib)

set(SixFiveOhTwoSource
    "Cpu.cpp"    
    "AddressingModes.cpp"
    "Opcodes/NoOperation.cpp"
)

set(SixFiveOhTwoHeader
    "Cpu.hpp"
    "CpuState.hpp"
    "Ram.hpp"
    "AddressingModes.hpp"
    "Opcodes/Opcodes.hpp"
    "Opcodes/NoOperation.hpp"
)

add_library(${SixFiveOhTwoLib} STATIC ${SixFiveOhTwoSource} ${SixFiveOhTwoHeader})

target_include_directories(${SixFiveOhTwoLib} PUBLIC .)

target_link_libraries(${SixFiveOhTwoLib} UtilityLib ClockLib)
