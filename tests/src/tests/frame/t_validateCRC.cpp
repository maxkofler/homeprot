#include <gtest/gtest.h>
#include "homeprot/frame.h"

TEST(Frame, validateCRC){
	HomeProt::Frame frame;

	frame.startByte = HomeProt::MtS;
	frame.slaveID = 0xFEDC;
	frame.lenPayload = 0;
	frame.applyCRC(0xFFFF);

	EXPECT_TRUE(frame.validateCRC(0xFFFF));
	frame.crc -= 10;
	EXPECT_FALSE(frame.validateCRC(0xFFFF));
}
