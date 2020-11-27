#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../Memory.hpp"

using namespace testing;

TEST(MemoryTest, Ram)
{
    // Setup.
    Memory::Ram ram;
    auto valueModifier = [](auto n)->u_int8_t{ return (n + 3) * 3; };

    // Write.
    for (size_t n = 0; n < Memory::Ram::Size; n++)
    {
        ram.Write(n, valueModifier(n));
    }

    // Verify.
    for (size_t n = 0; n < Memory::Ram::Size; n++)
    {
        uint8_t value = ram.Read(n);
        ASSERT_EQ(value, valueModifier(n));
    }
}

TEST(MemoryTest, Stack)
{
    // Setup.
    Memory::Ram ram;
    Memory::Stack stack(ram);
    size_t n = 0;

    // Fill stack.
    for (;n < 0x100; n++)
    {
        stack.Push(n);
    }

    // Verify half.
    for (size_t i = 0x0; i < 0x50; i++)
    {
        n--;
        ASSERT_EQ(n, stack.Peek());
        ASSERT_EQ(n, stack.Pop());
    }

    // Fill stack.
    for (;n < 0x100; n++)
    {
        stack.Push(n);
    }

    // Verify all.
    for (n--;n != 0; n--)
    {
        ASSERT_EQ(n, stack.Peek());
        ASSERT_EQ(n, stack.Pop());
    }
}

