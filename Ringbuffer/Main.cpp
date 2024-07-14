#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
int main(void)
{
	int iTemp = 0;

	Ringbuffer Ringbuffer1{};
	Ringbuffer1.vPrintRingBuffer();

	Ringbuffer1.s32WriteElement(42);
	Ringbuffer1.s32WriteElement(43);
	Ringbuffer1.s32WriteElement(44);
	Ringbuffer1.s32WriteElement(45);
	Ringbuffer1.s32WriteElement(46);
	Ringbuffer1.s32WriteElement(47);
	Ringbuffer1.s32WriteElement(48);
	Ringbuffer1.s32WriteElement(49);
	Ringbuffer1.s32WriteElement(50);

	Ringbuffer1.vPrintRingBuffer();

	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);

	Ringbuffer1.vPrintRingBuffer();

	Ringbuffer1.s32WriteElement(99);

	Ringbuffer1.vPrintRingBuffer();

	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);

	Ringbuffer1.vPrintRingBuffer();
}