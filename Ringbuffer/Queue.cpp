#include <iostream>
#include <cstdint>
#include "Queue.h"

using namespace std;
using namespace MyDataStructures;

Queue::~Queue() 
{
	cout << "Queue Destructor called" << endl;
}

Queue::Queue(const Queue& rq) noexcept(true) : Ringbuffer(rq)
{
#ifdef _DEBUG
	cout << "Copy Constructor is called" << endl;
#endif
}
Queue::Queue(Queue&& rq) noexcept(true) : Ringbuffer(std::move(rq))
{
#ifdef _DEBUG
	cout << "Move Constructor is called" << endl;
#endif
}

int32_t Queue::s32WriteElementFront(int32_t& rs32Element) {
	int32_t i32Ret = RINGBUFFER_FULL;

	if (u32NumberElements_ < u32SizeOfBuffer_)
	{
		ps32Buffer_[0U] = rs32Element;
		u32NumberElements_++;
		i32Ret = RINGBUFFER_OKAY;
	}
	
	return i32Ret;
}
