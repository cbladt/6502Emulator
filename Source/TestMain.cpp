#include <gtest/gtest.h>

#include <Test/MemoryTest.hpp>
#include <Test/CpuTest.hpp>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
