set(SixFiveOhTwoSource "Cpu.cpp")

add_library(SixFiveOhTwoLib STATIC ${SixFiveOhTwoSource})

target_include_directories(SixFiveOhTwoLib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
