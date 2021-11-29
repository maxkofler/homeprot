#ifndef __DUMMYBUS_H__
#define __DUMMYBUS_H__

#include "homeprot/bus.h"

class DummyBus : public HomeProt::Bus{

public:

	//
	//	Functions inherited from HomeProt::Bus
	//
	void					sendByte(unsigned char byte);

	/**
	 * @brief	Simulates an incoming byte on the bus
	 * @param	byte		The byte that should arrive
	 */
	void					emulateByteReceived(unsigned char byte);

};

#endif