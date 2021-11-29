#ifndef __BUS_H__
#define __BUS_H__

namespace HomeProt{
	
	class Bus{
	public:

		/**
		 * @brief	Registers a callback to notify the upper layer once a byte has been received
		 * @param	byteReceived		A function pointer to the callback function
		 */
		void						registerByteReceived(void (*byteReceived)(unsigned char byte));

		/**
		 * @brief	Notifies the upper layer through the registered callback that a byte has been received
		 * @param	byte			The received byte
		 */
		void						byteReceived(unsigned char byte);

		/**
		 * @brief	Call to the bus to send the supplied byte
		 * @param	byte			The byte to send
		 */
		virtual void				sendByte(unsigned char byte) = 0;

	#ifndef FRIEND_BUS
	private:
	#endif

		void 						(*_cb_byteReceived)(unsigned char byte) = nullptr;

	};

};

#endif