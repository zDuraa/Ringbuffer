#include <iostream>
#include <cstdint>
#include "Producer.h"

using namespace std;
using namespace Client;

Producer::Producer(Ringbuffer* pRingbuffer) {
#ifdef _DEBUG
	cout << "Producer Constructor called" << endl;
#endif
	this->pRingbuffer = pRingbuffer;
}
Producer::~Producer() {
#ifdef _DEBUG
	cout << "Producer Destructor called" << endl;
#endif
}
int32_t Producer::s32WriteToRingbuffer(int32_t& rs32Element) {
	return pRingbuffer->s32WriteElement(rs32Element);
}