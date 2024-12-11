#ifndef HEALTH_H
#define HEALTH_H

#include "powerUps.h";
#include "./pubSub.h"


class Health :public PowerUps, public Subscriber {
public:
	Health(int x, int y, int width, int height, PowerUpType type, int cost, int level);
	void tick();
	void receiveMessage(string channel, string message, void* data);

};
#endif