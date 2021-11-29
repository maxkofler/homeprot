#ifndef __SUBSYSTEM_H__
#define __SUBSYSTEM_H__

#include <stdint.h>

/**
 * @brief Implements a subsystem for HomeProt to work on
 */
class Subsystem{
public:
	void						registerByteReceived(void (*byteReceived)(uint8_t byte));

private:
	void 						(*byteReceived)(uint8_t byte);
};

#endif