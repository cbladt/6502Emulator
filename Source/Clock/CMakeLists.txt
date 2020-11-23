set(ClockLib ClockLib)

add_library(${ClockLib} INTERFACE)

target_include_directories(${ClockLib} INTERFACE .)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${ClockLib} INTERFACE Threads::Threads)
