#include <gtest/gtest.h>
#define FRIEND_BUS
#include "dummyBus.h"

static unsigned char charReceived;

static void testFun(unsigned char c){
	charReceived = c;
}

TEST(Bus, byteReceived){
	DummyBus dummyBus;
	HomeProt::Bus* bus = &dummyBus;

	charReceived = 0;
	dummyBus.emulateByteReceived('c');
	EXPECT_EQ(0, charReceived);

	bus->registerByteReceived(&testFun);
	
	dummyBus.emulateByteReceived('c');
	EXPECT_EQ('c', charReceived);
}
