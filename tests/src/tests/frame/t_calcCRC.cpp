#include <gtest/gtest.h>
#include "homeprot/frame.h"

#include <iostream>

TEST(Frame, calcCRC){
	HomeProt::Frame frame;

	frame.slaveID = 0xFFAA;
	frame.lenPayload = 0;

	frame.startByte = HomeProt::MtS;
	std::cout << "CRC = 0x" << std::hex << frame.calcCRC(0xFFFF) << std::endl;

	frame.startByte = HomeProt::StM;
	std::cout << "CRC = 0x" << std::hex << frame.calcCRC(0xFFFF) << std::endl;
}
