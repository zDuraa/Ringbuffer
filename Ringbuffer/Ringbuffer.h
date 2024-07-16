#pragma once
#include <cstdint>

#define RINGBUFFER_OKAY 0
#define RINGBUFFER_FULL -1
#define RINGBUFFER_EMPTY -2
#define RINGBUFFER_NULLPTR -3


namespace MyDataStructures
{
	class Ringbuffer
	{
	public:
		Ringbuffer();	
		Ringbuffer(uint32_t u32Size);
		~Ringbuffer();

		int32_t s32ReadElement(int32_t& rs32Element) noexcept; 
		int32_t s32WriteElement(const int32_t& rs32Element) noexcept;


		void vPrintRingBuffer(void)const noexcept;
		void vPrintRingbufferMembersValueAndAddress(void) const noexcept;
		void vPrintWriteElement(const int32_t& rs32Element, int32_t i32Ret)const noexcept;
		void vPrintReadElement(const int32_t& rs32Element, int32_t i32Ret)const noexcept;
	protected:

	private:
		uint32_t u32SizeOfBuffer_;
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberElements_;
		int32_t* ps32Buffer_;
	};
}
