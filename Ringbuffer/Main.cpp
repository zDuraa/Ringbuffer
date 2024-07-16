#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"


void vTestCreateObjectsRingbuffer(void);
using namespace MyDataStructures;
int main(void)
{
	
	vTestCreateObjectsRingbuffer();
	_CrtDumpMemoryLeaks();

	return 0;
}

void vTestCreateObjectsRingbuffer(void) 
{
	int iTemp = 0;
	uint32_t u32SizeOfRingbuffer = 8;
	Ringbuffer* pRingbuffer = new Ringbuffer( u32SizeOfRingbuffer );
	pRingbuffer->vPrintRingBuffer();

	pRingbuffer->s32WriteElement(42);
	pRingbuffer->s32WriteElement(43);
	pRingbuffer->s32WriteElement(44);
	pRingbuffer->s32WriteElement(45);
	pRingbuffer->s32WriteElement(46);
	pRingbuffer->s32WriteElement(47);
	pRingbuffer->s32WriteElement(48);
	pRingbuffer->s32WriteElement(49);
	pRingbuffer->s32WriteElement(50);

	pRingbuffer->vPrintRingBuffer();

	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);

	pRingbuffer->vPrintRingBuffer();

	pRingbuffer->s32WriteElement(99);

	pRingbuffer->vPrintRingBuffer();

	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);
	pRingbuffer->s32ReadElement(iTemp);

	pRingbuffer->vPrintRingBuffer();

	pRingbuffer->vPrintRingbufferMembersValueAndAddress();

}