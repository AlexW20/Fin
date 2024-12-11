#ifndef EXTENDEDRANGE_H
#define EXTENDEDRANGE_H

#include "powerUps.h";
#include "./pubSub.h"


class ExtendedRange :public PowerUps, public Subscriber {
public:
	ExtendedRange(int x, int y, int width, int height, PowerUpType type, int cost, int level);
	void tick();
	void receiveMessage(string channel, string message, void* data);

};
#endif