#include "speed.h"
#include "./playerEntity.h"
Speed::Speed(int x, int y, int width, int height, PowerUpType type, int cost, int level) :PowerUps(type, x, y, width, height)
{
	this->setCost(cost);
	this->setLevel(level);
	PubSub::subscribe("power_up", this);
}

void Speed::tick()
{

}

void Speed::receiveMessage(string channel, string message, void* data)
{
	if (channel == "power_up" && message == "speed") {
		PlayerEntity* player = (PlayerEntity*)data;
		player->setSpeedX(player->getSpeedX() * 1.25);
		player->setSpeedY(player->getSpeedY() * 1.25);
	}
}