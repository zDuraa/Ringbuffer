#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
int main(void)
{
	int iTemp = 0;

	Ringbuffer Ringbuffer1{};
	Ringbuffer1.s32WriteElement(0);
	Ringbuffer1.s32WriteElement(1);
	Ringbuffer1.s32WriteElement(2);
	Ringbuffer1.s32WriteElement(3);
	Ringbuffer1.s32WriteElement(4);
	Ringbuffer1.s32WriteElement(5);
	Ringbuffer1.s32WriteElement(6);
	Ringbuffer1.s32WriteElement(7);
	Ringbuffer1.s32WriteElement(8);

	Ringbuffer1.vPrintRingBuffer();

	Ringbuffer1.s32ReadElement(iTemp);
	Ringbuffer1.s32ReadElement(iTemp);

	Ringbuffer1.vPrintRingBuffer();

	Ringbuffer1.s32WriteElement(9);

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

	Ringbuffer1.s32WriteElement(99);
	Ringbuffer1.s32WriteElement(98);
	Ringbuffer1.s32WriteElement(97);

	Ringbuffer1.vPrintRingBuffer();
}