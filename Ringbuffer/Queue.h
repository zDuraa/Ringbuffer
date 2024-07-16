#pragma once
#include <cstdint>
#include "Ringbuffer.h"


namespace MyDataStructures {
	class Queue : public Ringbuffer
	{
		public:
			Queue() : Ringbuffer() {};
			Queue(uint32_t u32Size) noexcept(true) : Ringbuffer(u32Size) {};
			~Queue();


			Queue(const Queue& otherQueue) noexcept(true);
			Queue(Queue&& otherQueue) noexcept(true);

			int32_t s32WriteElementFront(int32_t& rs32Element);
		protected:
		private:

	};
}

