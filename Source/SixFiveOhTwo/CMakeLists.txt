set(SixFiveOhTwoLib SixFiveOhTwoLib)

set(SixFiveOhTwoSource
    "Cpu.cpp"
)

set(SixFiveOhTwoHeader
    "Cpu.hpp"
    "Flags.hpp"
)

add_library(${SixFiveOhTwoLib} STATIC ${SixFiveOhTwoSource} ${SixFiveOhTwoHeader})

target_include_directories(${SixFiveOhTwoLib} PRIVATE .)

target_link_libraries(${SixFiveOhTwoLib} UtilityLib BusLib)
