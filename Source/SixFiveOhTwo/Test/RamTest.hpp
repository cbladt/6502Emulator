#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../Ram.hpp"

using namespace testing;

TEST(RamTest, ReadWrite)
{
    // Setup.
    Ram ram;
    auto valueModifier = [](auto n)->u_int8_t{ return (n + 3) * 3; };

    // Write.
    for (size_t n = 0; n < RamSize; n++)
    {
        ram.Write(n, valueModifier(n));
    }

    // Verify.
    for (size_t n = 0; n < RamSize; n++)
    {
        uint8_t value = ram.Read(n);
        ASSERT_EQ(value, valueModifier(n));
    }
}

TEST(RamTest, Stack)
{

}

