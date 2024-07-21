#include <iostream>
#include <cstdint>
#include "Ringbuffer.h"
#include "pch.h"
#include "gtest/gtest.h"

using namespace MyDataStructures;
using namespace std;
using std::endl;

void Ringbuffer::vPrintRingBuffer(void)const noexcept
{
	cout << "-------------------------------------------------------------------" << endl;
	cout << "u32NumberElements_: " << u32NumberElements_ << endl;
	for (uint32_t u32Temp = 0; u32Temp < u32WritePos_; u32Temp++)
	{
		cout << "\t";
	}
	cout << "uiWritePos\n" << endl;
	for (uint32_t u32Temp = 0; u32Temp < u32SizeOfBuffer_; u32Temp++)
	{
		cout << ps32Buffer_[u32Temp] << "\t";
	}
	cout << endl;
	for (uint32_t u32Temp = 0; u32Temp < u32ReadPos_; u32Temp++)
	{
		cout << "\t";
	}
	cout << "uiReadPos" << endl;
	cout << "\n-------------------------------------------------------------------" << endl;
}

void Ringbuffer::vPrintWriteElement(const int32_t& rs32Element, int32_t i32Ret)const noexcept
{

	cout << "WriteElement with Val: " << rs32Element << " returned: " << i32Ret << endl;

}

void Ringbuffer::vPrintReadElement(const int32_t& rs32Element, int32_t i32Ret)const noexcept
{

	cout << "ReadElement Value: " << rs32Element << " return value: " << i32Ret << endl;;
}

void Ringbuffer::vPrintRingbufferMembersValueAndAddress(void) const noexcept
{
	cout << hex;
	cout << "--RingBufferMembers-----------------------------------------------" << endl;
	cout << "u32ReadPos_:         " << u32ReadPos_ << "        \t" << &u32ReadPos_ << endl;
	cout << "u32WritePos_:        " << u32WritePos_ << "        \t" << &u32WritePos_ << endl;
	cout << "u32SizeOfBuffer_:    " << u32SizeOfBuffer_ << "        \t" << &u32SizeOfBuffer_ << endl;
	cout << "u32NumberElements_:  " << u32NumberElements_ << "        \t" << &u32NumberElements_ << endl;
	cout << "as32Elements_:       " << ps32Buffer_[0] << "        \t" << &ps32Buffer_[0] << endl;
	cout << dec;
}