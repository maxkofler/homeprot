#include "homeprot/bus.h"

void HomeProt::Bus::byteReceived(unsigned char c){
	if (this->_cb_byteReceived != nullptr)
		this->_cb_byteReceived(c);
}