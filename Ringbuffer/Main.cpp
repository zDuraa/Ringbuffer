#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
int main(void)
{
	Ringbuffer Ringbuffer1{};
	Ringbuffer1.s32WriteElement(1);
	Ringbuffer1.vPrintRingBuffer();
}