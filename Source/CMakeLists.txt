cmake_minimum_required(VERSION 3.5)

set(ProjectName SourceApplication)
project(${ProjectName} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(DoLogDebug ON)
set(DoTest ON)

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
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDoLogDebug")
endif (DoLogDebug)

if (DoTest)
    find_package(Threads REQUIRED)

    set(GTestSrc ../googletest/googletest)
    set(GMockSrc ../googletest/googlemock)
    set(GTestFiles ${GTestSrc}/src/gtest-all.cc)
    set(GTestIncludes ${GTestSrc} ${GTestSrc}/include)
    if (NOT ${GMockSrc} STREQUAL "")
        list(APPEND GTestFiles ${GMockSrc}/src/gmock-all.cc)
        list(APPEND GTestIncludes ${GMockSrc} ${GMockSrc}/include)
    endif ()

    include_directories(${GTestIncludes})

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDoTest")

    set(Source TestMain.cpp ${GTestFiles})
else(DoTest)
    set(Source Main.cpp)
endif (DoTest)

# Toolchain
# TODO Move to seperate toolchain file?
#set(Path "D:\\Program Files\\mingw-w64\\x86_64-8.1.0-posix-seh-rt_v6-rev0\\mingw64\\bin\\")
#set(Ext ".exe")
set(Path "/usr/bin/")

set(gcc "${Path}gcc")
set(g++ "${Path}g++")
set(tc ${gcc})
set(CMAKE_C_COMPILER "${gcc}${Ext}")
set(CMAKE_CXX_COMPILER "${g++}${Ext}")
set(CMAKE_AR "${tc}-ar${Ext}")
set(CMAKE_NM "${tc}-nm${Ext}")
set(CMAKE_RANLIB "${tc}-ranlib${Ext}")
SET(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> qcs <TARGET> <LINK_FLAGS> <OBJECTS>")
SET(CMAKE_C_ARCHIVE_FINISH true)
SET(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> qcs <TARGET> <LINK_FLAGS> <OBJECTS>")
SET(CMAKE_CXX_ARCHIVE_FINISH true)

# Find Sources
add_subdirectory("Utility")
add_subdirectory("SixFiveOhTwo")

# Create Exe
add_executable(${ProjectName} ${Source})
target_link_libraries(${ProjectName} UtilityLib)
target_link_libraries(${ProjectName} SixFiveOhTwoLib)

find_package(Threads REQUIRED)
target_link_libraries(${ProjectName} Threads::Threads)
