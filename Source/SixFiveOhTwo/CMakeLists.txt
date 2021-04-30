set(SixFiveOhTwoLib SixFiveOhTwoLib)

set(SixFiveOhTwoSource
    "Cpu.cpp"        
)

set(SixFiveOhTwoHeader
    "Cpu.hpp"
    "CpuState.hpp"
	"Memory.hpp"
    "AddressingModes.hpp"
    "Opcodes/Opcodes.hpp"    
)

add_library(${SixFiveOhTwoLib} STATIC ${SixFiveOhTwoSource} ${SixFiveOhTwoHeader})

target_include_directories(${SixFiveOhTwoLib} PUBLIC .)

target_link_libraries(${SixFiveOhTwoLib} UtilityLib)
