#pragma once
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
using namespace std;
namespace Client
{
	class Consumer
	{
		public:
			Consumer(Ringbuffer* pRingbuffer);
			~Consumer();
			int32_t s32ReadFromRingbuffer(int32_t& rs32Element);
		protected:
		private:
			Ringbuffer* pRingbuffer;

	};
}

