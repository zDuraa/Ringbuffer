#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "IOChannel.h"

void vTestCreateObjectsRingbuffer(void);
using namespace MyDataStructures;
using namespace Client;
int main(void)
{
	
	vTestCreateObjectsRingbuffer();
	_CrtDumpMemoryLeaks();

	return 0;
}

void vTestCreateObjectsRingbuffer(void) 
{
	int iTemp = 5;
	uint32_t u32SizeOfRingbuffer = 8;
	Ringbuffer* pRingbuffer = new Ringbuffer( u32SizeOfRingbuffer );
	Producer Producer{ pRingbuffer };
	Consumer* pConsumer = new Consumer{ pRingbuffer };
	IOChannel* pIOChannel = new IOChannel{};

	pIOChannel->s32WriteElementToChannel(1, iTemp);
	iTemp = 0;
	pIOChannel->s32ReadElementFromChannel(1, iTemp);
	
	pRingbuffer->vPrintRingBuffer();
	
	iTemp = 42;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 43;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 44;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 45;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 46;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 47;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 48;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 49;
	Producer.s32WriteToRingbuffer(iTemp);
	iTemp = 50;
	Producer.s32WriteToRingbuffer(iTemp);

	pRingbuffer->vPrintRingBuffer();

	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);

	pRingbuffer->vPrintRingBuffer();

	iTemp = 99;
	Producer.s32WriteToRingbuffer(iTemp);

	pRingbuffer->vPrintRingBuffer();

	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);
	pConsumer->s32ReadFromRingbuffer(iTemp);

	pRingbuffer->vPrintRingBuffer();

	pRingbuffer->vPrintRingbufferMembersValueAndAddress();

}