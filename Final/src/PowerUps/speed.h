#ifndef SPEED_H
#define SPEED_H

#include "powerUps.h";
#include "./pubSub.h"


class Speed :public PowerUps, public Subscriber {
public:
	Speed(int x, int y, int width, int height, PowerUpType type, int cost, int level);
	void tick();
	void receiveMessage(string channel, string message, void* data);

};
#endif