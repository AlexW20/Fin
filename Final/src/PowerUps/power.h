#ifndef POWER_H
#define POWER_H

#include "powerUps.h";
#include "./pubSub.h"


class Power :public PowerUps, public Subscriber {
public:
	Power(int x, int y, int width, int height, PowerUpType type, int cost, int level);
	void tick();
	void receiveMessage(string channel, string message, void* data);

};
#endif