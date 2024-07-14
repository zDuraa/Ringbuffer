#pragma once
#include <cstdint>

#define RINGBUFFER_OKAY 0
#define RINGBUFFER_FULL -1
#define RINGBUFFER_EMPTY -2
#define RINGBUFFER_MAXELEMENTS 8 

namespace MyDataStructures
{
	class Ringbuffer
	{
	public:
		Ringbuffer();

		int32_t s32ReadElement(int32_t& rs32Element);
		int32_t s32WriteElement(const int32_t& rs32Element);
		void vPrintRingBuffer(void);
		void vPrintWriteElement(const int32_t& rs32Element, int32_t i32Ret);
		void vPrintReadElement(const int32_t& rs32Element, int32_t i32Ret);
	protected:

	private:
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberElements_;
		uint32_t as32Elements_[RINGBUFFER_MAXELEMENTS];
	};
}
