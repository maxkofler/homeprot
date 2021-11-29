#ifndef __LAYER2_H__
#define __LAYER2_H__

#include "homeprot/bus.h"

namespace HomeProt{

	class Layer2{

	public:
		Layer2(HomeProt::Bus& bus);

	#ifndef FRIEND_LAYER2
	private:
	#endif
		/**
		 * @brief	Gets called by the Bus once a byte has been received
		 * @param	byte			The byte that has been received
		 */
		static void					byteReceived(unsigned char byte);


		/**
		 * @brief	Holds how long the current frame is (0 = no frame started)
		 */
		unsigned char				_frameLen = -1;
	};

};

#endif
