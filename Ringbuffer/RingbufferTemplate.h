#pragma once
#include <cstdint>
#include <iostream>

#define RINGBUFFER_OKAY 0
#define RINGBUFFER_FULL -1
#define RINGBUFFER_EMPTY -2
#define RINGBUFFER_NULLPTR -3

namespace MyDataStructures
{
	template <typename T, uint32_t u32Size> 
	class RingbufferTemplate
	{
	public:
		RingbufferTemplate() {
			u32SizeOfBuffer_ = u32Size;
			pBuffer_ = new T[u32SizeOfBuffer_]{};
			u32ReadPos_ = 0;
			u32WritePos_ = 0;
			u32NumberElements_ = 0;
		}
		~RingbufferTemplate() 
		{
			delete[] pBuffer_;
		}

		int32_t s32ReadElement(T& rs32Element) noexcept
		{
			int32_t i32Ret = RINGBUFFER_EMPTY;
			if (pBuffer_ != nullptr)
			{
				if (u32NumberElements_ > 0U)
				{
					rs32Element = pBuffer_[u32ReadPos_];
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

				cout << "ReadElement Value: " << rs32Element << " return value: " << i32Ret << endl;
			}
			else {
				i32Ret = RINGBUFFER_NULLPTR;
			}

			return i32Ret;
		}
		int32_t s32WriteElement(const T& rs32Element) noexcept
		{
			int32_t i32Ret = RINGBUFFER_EMPTY;

			if (pBuffer_ != nullptr)
			{
				if (u32NumberElements_ < u32SizeOfBuffer_)
				{
					pBuffer_[u32WritePos_] = rs32Element;
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
				cout << "WriteElement with Val: " << rs32Element << " returned: " << i32Ret << endl;
			}
			else {
				i32Ret = RINGBUFFER_NULLPTR;
			}

			return i32Ret;
		}

		RingbufferTemplate(const RingbufferTemplate& otherRingBuffer) noexcept(true) = default;
		RingbufferTemplate(RingbufferTemplate&& otherRingBuffer) noexcept(true) = default;
	protected:
		T* pBuffer_;
		uint32_t u32SizeOfBuffer_;
		uint32_t u32ReadPos_;
		uint32_t u32WritePos_;
		uint32_t u32NumberElements_;
	private:


		friend std::ostream& operator<<(std::ostream& ostr, const RingbufferTemplate& rb) {
			ostr << "-------------------------------------------------------------------" << endl;
			ostr << "u32NumberElements_: " << rb.u32NumberElements_ << endl;
			for (uint32_t u32Temp = 0; u32Temp < rb.u32WritePos_; u32Temp++)
			{
				ostr << "\t";
			}
			ostr << "uiWritePos\n" << endl;
			for (uint32_t u32Temp = 0; u32Temp < rb.u32SizeOfBuffer_; u32Temp++)
			{
				ostr << rb.pBuffer_[u32Temp] << "\t";
			}
			ostr << endl;
			for (uint32_t u32Temp = 0; u32Temp < rb.u32ReadPos_; u32Temp++)
			{
				ostr << "\t";
			}
			ostr << "uiReadPos" << endl;
			ostr << "\n-------------------------------------------------------------------" << endl;
			return ostr;
		}
	};


}