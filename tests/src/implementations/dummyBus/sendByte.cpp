#include "dummyBus.h"

#include <iostream>

void DummyBus::sendByte(unsigned char byte){
	std::cout << "Sending 0x" << std::hex << byte << std::endl;
}