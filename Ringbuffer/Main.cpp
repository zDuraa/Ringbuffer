#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"
#include "Consumer.h"
#include "Producer.h"
#include "IOChannel.h"
#include "Queue.h"
#include "RingbufferTemplate.h"

void vTestCreateObjectsRingbuffer(void);
using namespace MyDataStructures;
using namespace Client;

#define TEST 3
int main(void)
{
	
	vTestCreateObjectsRingbuffer();
	_CrtDumpMemoryLeaks();

	return 0;
}

void vTestCreateObjectsRingbuffer(void) 
{
	int32_t iTemp = 5;
//Test Queue
#if TEST == 0
	Queue* pQueue1 = new Queue{ 8 };
	
	
	pQueue1->s32WriteElement(iTemp);
	iTemp = 43;
	pQueue1->s32WriteElement(iTemp);
	iTemp = 44;
	pQueue1->s32WriteElement(iTemp);
	iTemp = 10;
	pQueue1->s32WriteElementFront(iTemp);
	

	Queue* pQueue2 = new MyDataStructures::Queue(*pQueue1);
	pQueue2->vPrintRingBuffer();
	Queue* pQueue3 = new MyDataStructures::Queue(std::move(*pQueue1));
	pQueue3->vPrintRingBuffer();

	
//Test Ringbuffer with Producer and Consumer
#elif TEST == 1
	uint32_t u32SizeOfRingbuffer = 8;
	Ringbuffer* pRingbuffer = new Ringbuffer(u32SizeOfRingbuffer);
	Producer Producer{ pRingbuffer };
	Consumer* pConsumer = new Consumer{ pRingbuffer };

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


//Test IOChannel
#elif TEST == 2
	IOChannel* pIOChannel = new IOChannel{};

	iTemp = 1;
	pIOChannel->s32WriteElementToChannel(1, iTemp);
	iTemp = 2;
	pIOChannel->s32WriteElementToChannel(1, iTemp);
	pIOChannel->s32WriteElementToChannel(2, iTemp);
	
	pIOChannel->s32ReadElementFromChannel(1, iTemp);
	pIOChannel->s32ReadElementFromChannel(2, iTemp);

//Test Template Ringbuffer
#elif TEST == 3
	RingbufferTemplate<int, 8> ringBufferTemplate;
	ringBufferTemplate.s32WriteElement(iTemp);
	 iTemp = 10;
	ringBufferTemplate.s32WriteElement(iTemp);
	 iTemp = 15;
	ringBufferTemplate.s32WriteElement(iTemp);
	 iTemp = 20;
	ringBufferTemplate.s32WriteElement(iTemp);
	cout << ringBufferTemplate << endl;
#endif 

	

	
}