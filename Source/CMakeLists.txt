cmake_minimum_required(VERSION 3.5)

project(Source LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(DoLogDebug ON)

set(Flags "-Werror -flto -Wl,-flto")
set(FlagsDebug "-O0")
set(FlagsRelease "-O2")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${Flags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Flags}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${FlagsDebug}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${FlagsDebug}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${FlagsRelease}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${FlagsRelease}")

# Enable debug output.
if (DoLogDebug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DLOG_DEBUG")
endif (DoLogDebug)

# Toolchain
# TODO Move to seperate toolchain file?
set(Path "C:\\MinGW\\bin\\")
set(gcc "${Path}gcc")
set(g++ "${Path}g++")
set(tc ${gcc})
set(CMAKE_C_COMPILER "${gcc}.exe")
set(CMAKE_CXX_COMPILER "${g++}.exe")
set(CMAKE_AR "${tc}-ar.exe")
set(CMAKE_NM "${tc}-nm.exe")
set(CMAKE_RANLIB "${tc}-ranlib.exe")
SET(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> qcs <TARGET> <LINK_FLAGS> <OBJECTS>")
SET(CMAKE_C_ARCHIVE_FINISH true)
SET(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> qcs <TARGET> <LINK_FLAGS> <OBJECTS>")
SET(CMAKE_CXX_ARCHIVE_FINISH true)

add_executable(Source Main.cpp)
target_include_directories(Source PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
