#include "pch.h"
#include <stdint.h>

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}


//Testing Writing to Ringbuffer
TEST(RingbufferWriteAttributes, writeRingbuffer)
{
    int value = 42;

    MyDataStructures::Ringbuffer ringbuffer;
    ringbuffer.s32WriteElement(value);
    int Result = ringbuffer.s32ReadElement(value);
    EXPECT_EQ(0, Result);
}

//Testing Reading of Ringbuffer
TEST(RingbufferReadAttributes, readRingbuffer)
{
    int value = 43;

    MyDataStructures::Ringbuffer ringbuffer;

    ringbuffer.s32WriteElement(43);

    int Result = ringbuffer.s32ReadElement(value);
    EXPECT_EQ(0, Result);
}


//Testing full Ringbuffer
TEST(RingbufferFullBuffer, fullRingbuffer)
{
    MyDataStructures::Ringbuffer ringbuffer;

    for (int iVal = 42; iVal < 51; iVal++)
    {
        ringbuffer.s32WriteElement(iVal);
    }

    ringbuffer.s32WriteElement(51);
    int bufferFull = ringbuffer.s32WriteElement(51);
    EXPECT_EQ(-1, bufferFull);
}

//Testing empty Ringbuffer
TEST(RingbufferEmptyBuffer, emptyRingbuffer)
{
    int temp = 51;
    MyDataStructures::Ringbuffer ringbuffer;

    int bufferFull = ringbuffer.s32ReadElement(temp);
    EXPECT_EQ(-2, bufferFull);
}