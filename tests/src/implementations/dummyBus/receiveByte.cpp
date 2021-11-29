#include "dummyBus.h"

void DummyBus::emulateByteReceived(unsigned char byte){
	this->byteReceived(byte);
}