cmake_minimum_required(VERSION 3.5)

project(Source LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(Flags "-Werror -flto -Wl,-flto")
set(FlagsDebug "-O0")
set(FlagsRelease "O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${Flags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Flags}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${FlagsDebug}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${FlagsDebug}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${FlagsRelease}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${FlagsRelease}")

# Enable debug output.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOG_DEBUG")

add_executable(Source Main.cpp)
