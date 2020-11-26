#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../Cpu.hpp"

using namespace testing;

TEST(CpuTest, Reset)
{
    SixFiveOhTwo::Cpu cpu;

    cpu.GetRam().Write(SixFiveOhTwo::Cpu::ProgramCounterDefault, 13);
    cpu.GetRam().Write(SixFiveOhTwo::Cpu::ProgramCounterDefault + 1, 37);

    cpu.Reset();

    ASSERT_EQ(9485, cpu.GetInternalState().ProgramCounter);

    ASSERT_TRUE(cpu.GetInternalState().Unused);

    ASSERT_EQ(8, cpu.GetInternalState().CyclesLeft);
}

TEST(CpuTest, InterruptRequest_Success)
{
    SixFiveOhTwo::Cpu cpu;

    cpu.GetInternalState().DisableInterrupt = false;

    ASSERT_TRUE(cpu.InterruptRequest());
}

TEST(CpuTest, InterruptRequest_Failure)
{
    SixFiveOhTwo::Cpu cpu;

    cpu.GetInternalState().DisableInterrupt = true;

    ASSERT_FALSE(cpu.InterruptRequest());
}

TEST(CpuTest, Interrupt)
{
    SixFiveOhTwo::Cpu cpu;
    cpu.GetInternalState().RegisterReset();
    cpu.GetInternalState().DisableInterrupt = true;
    cpu.GetInternalState().ProgramCounter = 1337;

    cpu.Interrupt();

    // Verify that ProgramCounter is pushed to stack.
    ASSERT_EQ(0x05, cpu.GetRam().StackPeek(-3));
    ASSERT_EQ(0x39, cpu.GetRam().StackPeek(-2));

    // Verify registers.
    ASSERT_FALSE(cpu.GetInternalState().Break);
    ASSERT_TRUE(cpu.GetInternalState().Unused);
    ASSERT_TRUE(cpu.GetInternalState().DisableInterrupt);
    ASSERT_EQ(7, cpu.GetInternalState().CyclesLeft);
    //ASSERT_EQ(0, cpu.GetInternalState().ProgramCounter); TODO
    //auto a = cpu.GetRam().StackPeek(-1);
}
