#pragma once
#include <cstdint>
#include "Ringbuffer.h"


using namespace MyDataStructures;
using namespace std;
namespace Client
{
	class Producer
	{
	public:
		Producer(Ringbuffer* pRingbuffer);
		~Producer();
		int32_t s32WriteToRingbuffer(int32_t& rs32Element);
	protected:
	private:
		Ringbuffer* pRingbuffer;
	};
}
