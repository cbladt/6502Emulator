set(SixFiveOhTwoLib SixFiveOhTwoLib)

set(SixFiveOhTwoSource
    "Cpu.cpp"    
    "Tasks/Reset.cpp"
    "Tasks/Interrupt.cpp"
)

set(SixFiveOhTwoHeader
    "Cpu.hpp"
    "Tasks/Reset.hpp"
    "Tasks/Interrupt.hpp"
)

add_library(${SixFiveOhTwoLib} STATIC ${SixFiveOhTwoSource} ${SixFiveOhTwoHeader})

target_include_directories(${SixFiveOhTwoLib} PUBLIC .)

target_link_libraries(${SixFiveOhTwoLib} UtilityLib BusLib)
