#include <gtest/gtest.h>
#define FRIEND_BUS
#include "dummyBus.h"

static unsigned char charReceived;

static void testFun(unsigned char c){
	charReceived = c;
}

TEST(Bus, registerByteReceived){
	HomeProt::Bus *bus = new DummyBus();

	EXPECT_EQ(nullptr, bus->_cb_byteReceived);
	bus->registerByteReceived(&testFun);
	EXPECT_EQ(&testFun, bus->_cb_byteReceived);
}
