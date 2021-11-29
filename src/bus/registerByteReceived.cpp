#include "homeprot/bus.h"

void HomeProt::Bus::registerByteReceived(void (*byteReceived)(unsigned char byte)){
	this->_cb_byteReceived = byteReceived;
}