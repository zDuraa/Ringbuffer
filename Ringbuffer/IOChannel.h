#pragma once
#include <cstdint>
#include "Ringbuffer.h"

using namespace MyDataStructures;
namespace MyDataStructures
{
	class IOChannel 
	{
	public:
		IOChannel();
		~IOChannel();		
		int32_t s32WriteElementToChannel(uint32_t u32Channel, const int32_t& rs32Element);
		int32_t s32ReadElementFromChannel(uint32_t u32Channel, int32_t& rs32Element);
	protected:
	private:
		Ringbuffer Channels[3U];
	};
}
