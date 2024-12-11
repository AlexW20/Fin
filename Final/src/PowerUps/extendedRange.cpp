#include "extendedRange.h"
#include "./playerEntity.h"
ExtendedRange::ExtendedRange(int x, int y, int width, int height, PowerUpType type, int cost, int level) :PowerUps(type, x, y, width, height)
{
	this->setCost(cost);
	this->setLevel(level);
	PubSub::subscribe("power_up", this);
}

void ExtendedRange::tick()
{

}

void ExtendedRange::receiveMessage(string channel, string message, void* data)
{
	if (channel == "power_up" && message == "extended_range") {
		PlayerEntity* player = (PlayerEntity*)data;
		player->setAttackRange(player->getAttackRange() * 1.2);
	}
}