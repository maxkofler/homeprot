#include <gtest/gtest.h>
#include "homeprot/frame.h"

TEST(Frame, applyCRC){
	HomeProt::Frame frame;

	frame.startByte = HomeProt::MtS;
	frame.slaveID = 0xFEDC;
	frame.lenPayload = 0;

	uint16_t crc = frame.calcCRC(0xFFFF);
	frame.applyCRC(0xFFFF);
	EXPECT_EQ(crc, frame.crc);

	//Generate CRC with wrong start value
	frame.applyCRC(0xAAFF);
	EXPECT_NE(crc, frame.crc);

}
