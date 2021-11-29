#ifndef __FRAME_H__
#define __FRAME_H__

#include <stdint.h>

#include <iostream>

namespace HomeProt {
	/**
	 * @brief	Master to slave
	 */
	const static uint8_t MtS = 0x55;

	/**
	 * @brief	Slave to master
	 */
	const static uint8_t StM = 0xAA;

	struct __attribute__((__packed__)) frame_s{
		uint8_t				startByte;
		uint16_t			slaveID;
		uint8_t				lenPayload;
		uint8_t*			payload;
		uint16_t			crc;

		/**
		 * @brief	Validates the CRC of this frame
		 * @param	start	Startnumber (0xFFFF in HomeProt)
		 * @return	Validity
		 */
		bool				validateCRC(uint16_t start){
			return crc == calcCRC(start);
		}

		/**
		 * @brief	Sets the CRC of this frame
		 * @param	start	Startnumber (0xFFFF in HomeProt)
		 */
		void				applyCRC(uint16_t start){
			crc = calcCRC(start);
		}

		/**
		 * @brief	Calculates the CRC checksum of this frame
		 * @param	start	Startnumber (0xFFFF in HomeProt)
		 * @return	The calculated CRC checksum
		 */
		uint16_t			calcCRC(uint16_t start){
			int length = lenPayload + 4;
			uint8_t* pData = &startByte;

			while(length) {
				uint8_t byte = *pData;
				for(uint8_t b = 0; b < 8; b++) {
					start ^= (byte & 0x01u);
					start = (start & 0x01u) ? ((start >> 1) ^ 0x8408u) : (start >> 1);
					byte >>= 1;
				}

				pData++;
				length--;
			}
			return start;
		}

	};

	typedef frame_s Frame;

}

#endif
