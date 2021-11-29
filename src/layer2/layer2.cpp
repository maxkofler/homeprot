#include "homeprot/layer2.h"

HomeProt::Layer2::Layer2(HomeProt::Bus& bus){
	bus.registerByteReceived(&this->byteReceived);
}
