#include "power.h"
#include "./playerEntity.h"
Power::Power(int x, int y, int width, int height, PowerUpType type, int cost, int level) :PowerUps(type, x, y, width, height)
{
	this->setCost(cost);
	this->setLevel(level);
	PubSub::subscribe("power_up", this);
}

void Power::tick()
{

}

void Power::receiveMessage(string channel, string message, void* data)
{
	if (channel == "power_up" && message == "power") {
		PlayerEntity* player = (PlayerEntity*)data;
		player->setPower(player->getPower() * 1.5);
	}
}