#include <iostream>
#include <cstdint>
#include <assert.h>
#include "IOChannel.h"

using namespace std;
using namespace MyDataStructures;

IOChannel::IOChannel()
{
#ifdef _DEBUG
	cout << "IOChannel Constructor called" << endl;
#endif
}

IOChannel::~IOChannel()
{
#ifdef _DEBUG
	cout << "IOChannel Destructor called" << endl;
#endif 
}


int32_t IOChannel::s32WriteElementToChannel(uint32_t u32Channel, const int32_t& rs32Element) {
	assert(u32Channel < 3);
	return Channels[u32Channel].s32WriteElement(rs32Element);
}
int32_t IOChannel::s32ReadElementFromChannel(uint32_t u32Channel, int32_t& rs32Element) {
	assert(u32Channel < 3);
	return Channels[u32Channel].s32ReadElement(rs32Element);
}