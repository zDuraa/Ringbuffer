#include "Ringbuffer.h"
#include <iostream>
#include <cstdint>
#include "pch.h"
#include "gtest/gtest.h"

using MyDataStructures::Ringbuffer;
using namespace std;
using std::endl;

Ringbuffer::Ringbuffer()
{
	u32SizeOfBuffer_ = 10U;
	ps32Buffer_ = new int[u32SizeOfBuffer_] {};
	u32ReadPos_ = 0;
	u32WritePos_ = 0;
	u32NumberElements_ = 0;
}

Ringbuffer::Ringbuffer(uint32_t u32Size)
{
	u32SizeOfBuffer_ = u32Size;
	ps32Buffer_ = new int[u32SizeOfBuffer_] {};
	u32ReadPos_ = 0;
	u32WritePos_ = 0;
	u32NumberElements_ = 0;
}

Ringbuffer::~Ringbuffer()
{
	delete ps32Buffer_;
}

int32_t Ringbuffer::s32ReadElement(int32_t& rs32Element) noexcept
{
	int32_t i32Ret = RINGBUFFER_EMPTY;
	if (ps32Buffer_ != nullptr)
	{
		if (u32NumberElements_ > 0U) 
		{
			rs32Element = ps32Buffer_[u32ReadPos_];
			u32NumberElements_--;
			u32ReadPos_++;
			i32Ret = RINGBUFFER_OKAY;
			if (u32ReadPos_ >= u32SizeOfBuffer_) 
			{
				u32ReadPos_ = 0;
			}
		}
		else {
			i32Ret = RINGBUFFER_EMPTY;		
		}

		vPrintReadElement(rs32Element, i32Ret);
	}
	else {
		i32Ret = RINGBUFFER_NULLPTR;
	}
	
	return i32Ret;
}

int32_t Ringbuffer::s32WriteElement(const int32_t& rs32Element) noexcept
{
	int32_t i32Ret = RINGBUFFER_EMPTY;
	
	if (ps32Buffer_ != nullptr)
	{
		if (u32NumberElements_ < u32SizeOfBuffer_)
		{
			ps32Buffer_[u32WritePos_] = rs32Element;
			u32WritePos_++;
			u32NumberElements_++;
			i32Ret = RINGBUFFER_OKAY;
		}
		else {
			i32Ret = RINGBUFFER_FULL;
			if (u32WritePos_ >= u32SizeOfBuffer_) 
			{
				u32WritePos_ = 0;
			}
		}
			vPrintWriteElement(rs32Element, i32Ret);
	}
	else {
		i32Ret = RINGBUFFER_NULLPTR;
	}
	
	return i32Ret;
}
