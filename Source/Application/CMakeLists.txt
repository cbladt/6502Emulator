set(ApplicationSource "Main.cpp")

add_library(ApplicationLib STATIC ${ApplicationSource})

target_include_directories(ApplicationLib PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
