#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
using namespace std;

Ringbuffer::Ringbuffer()
{
	this->u32ReadPos_ = 0U;
	this->u32WritePos_ = 0U;
	this->u32NumberElements_ = 0U;

	for (uint32_t u32Temp = 0; u32Temp < RINGBUFFER_MAXELEMENTS; u32Temp++) 
	{
		as32Elements_[u32Temp] = 0U;
	}
}

int32_t Ringbuffer::s32ReadElement(int32_t& rs32Element)
{

	return 0U;
}
int32_t Ringbuffer::s32WriteElement(const int32_t& rs32Element)
{
	as32Elements_[u32WritePos_] = rs32Element;

	if (u32WritePos_ < 8U) 
	{
		u32WritePos_ = 0U;
	}
	else {
		u32WritePos_++;
	}
	
	return 0U;
}
void Ringbuffer::vPrintRingBuffer(void)
{
	cout << as32Elements_[0] << endl;
}