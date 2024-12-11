#include "health.h"
#include "./playerEntity.h"
Health::Health(int x, int y, int width, int height, PowerUpType type, int cost, int level) :PowerUps(type, x, y, width, height)
{
	this->setCost(cost);
	this->setLevel(level);
	PubSub::subscribe("power_up", this);
}

void Health::tick()
{

}

void Health::receiveMessage(string channel, string message, void* data)
{
	if (channel == "power_up" && message == "health") {
		PlayerEntity* player = (PlayerEntity*)data;
		player->setHealth(player->getMaxHealth());
		player->getAttackRange();
	}
}