#include <iostream>
#include "Consumer.h"

using namespace std;
using namespace Client;

Consumer::~Consumer() 
{
#ifdef _DEBUG
	cout << "Consumer Destructor called" << endl;
#endif
}

Consumer::Consumer(Ringbuffer* pRingbuffer) {
	cout << "Consumer Constructor called" << endl;
	this->pRingbuffer = pRingbuffer;
}

int32_t Consumer::s32ReadFromRingbuffer(int32_t& rs32Element) {

	return pRingbuffer->s32ReadElement(rs32Element);
}