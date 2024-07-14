#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
using namespace std;
using std::endl;
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
	int32_t i32Ret = RINGBUFFER_EMPTY;

	if (u32NumberElements_ > 0U) {
		rs32Element = as32Elements_[u32ReadPos_];
		u32NumberElements_--;
		u32ReadPos_++;
		i32Ret = RINGBUFFER_OKAY;
		if (u32ReadPos_ >= RINGBUFFER_MAXELEMENTS) {
			u32ReadPos_ = 0;
		}
	}
	else 
	{
		i32Ret = RINGBUFFER_EMPTY;		
	}

	vPrintReadElement(rs32Element, i32Ret);
	return i32Ret;
}

int32_t Ringbuffer::s32WriteElement(const int32_t& rs32Element)
{
	int32_t i32Ret = RINGBUFFER_EMPTY;
	
	if (u32NumberElements_ < RINGBUFFER_MAXELEMENTS)
	{
		as32Elements_[u32WritePos_] = rs32Element;
		u32WritePos_++;
		u32NumberElements_++;
		i32Ret = RINGBUFFER_OKAY;
	}
	else {
		i32Ret = RINGBUFFER_FULL;
		if (u32WritePos_ >= RINGBUFFER_MAXELEMENTS) {
			u32WritePos_ = 0;
		}
	}
	vPrintWriteElement(rs32Element, i32Ret);
	return i32Ret;
}
void Ringbuffer::vPrintRingBuffer(void)
{
	cout << "-------------------------------------------------------------------" << endl;
	cout << "u32NumberElements_: " << u32NumberElements_<< endl;
	for (uint32_t u32Temp = 0; u32Temp < u32WritePos_; u32Temp++)
	{
		cout << "\t";
	}
	cout << "uiWritePos\n" << endl;
	for (uint32_t u32Temp = 0; u32Temp < RINGBUFFER_MAXELEMENTS; u32Temp++)
	{
		cout << as32Elements_[u32Temp]<< "\t";
	}
	cout << endl;
	for (uint32_t u32Temp = 0; u32Temp < u32ReadPos_; u32Temp++)
	{
		cout << "\t";
	}
	cout << "uiReadPos" << endl;
	cout << "\n-------------------------------------------------------------------" << endl;;
}

void Ringbuffer::vPrintWriteElement(const int32_t& rs32Element, int32_t i32Ret)
{
	
	cout <<"WriteElement with Val: " << rs32Element << " returned: " << i32Ret<< endl;

}

void Ringbuffer::vPrintReadElement(const int32_t& rs32Element, int32_t i32Ret)
{
	
	cout << "ReadElement Value: " << rs32Element << " return value: "<< i32Ret << endl;;
}