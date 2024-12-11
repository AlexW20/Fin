#include "playerEntity.h"
#include "world.h"
#include "raylib.h"
#include "PowerUps/powerUps.h"
using namespace std;

PlayerEntity::PlayerEntity(float x, float y, int width, int height, EntityType type, string playerName, float health) :Entity(x, y, width, height, type, playerName) {
	setHealth(health);
	setMaxHealth(health);
	this->setSpeedX(2);
	this->setSpeedY(2);
	this->setPower(2);
	PubSub::subscribe("action", this);
	PubSub::subscribe("stations", this);
	PubSub::subscribe("power_up", this);
	Vector2 position = { getXPos(), getYPos() };
	PubSub::publish("player", "location", &position);
}
PlayerEntity::~PlayerEntity() {
	PubSub::unsubscribe("action", this);
	PubSub::unsubscribe("stations", this);
	PubSub::unsubscribe("power_up", this);

}

void PlayerEntity::tick()
{

	if (getMoving()) {

		if (movementCountdown > 0)
		{

			movementCountdown--;

			if (movementCountdown == 0)
			{
				setMoving(false);


			}
			else
			{

				switch (getFacing()) {
				case right:
					setXPos(getXPos() + this->getSpeedX());
					break;
				case left:
					setXPos(getXPos() - this->getSpeedX());

					break;
				case up:
					setYPos(getYPos() - this->getSpeedY());
					break;
				case down:
					setYPos(getYPos() + this->getSpeedY());
					break;
				}


			}

		}
		Vector2 position = { getXPos(), getYPos() };
		PubSub::publish("player", "location", &position);
	}


}
void PlayerEntity::receiveMessage(string channel, string message, void* data) {

	if (channel == "power_up" && message == "buy") {
		PowerUps* power = (PowerUps*)data;
		switch (power->getType()) {
		case healthType:
			PubSub::publish("power_up", "health", this);
			break;
		case speedType:
			PubSub::publish("power_up", "speed", this);
			break;
		case powerType:
			PubSub::publish("power_up", "power", this);
			break;
		case extendedRangeType:
			PubSub::publish("power_up", "extended_range", this);
			break;
		}
	}
	if (channel == "action" && message == "player") {
		userAction* action = (userAction*)data;
		if (*action == PlayerHit) {
			PubSub::publish("action", "attack", this);
		}
		if (*action == PlayerRight)
		{
			if (getXPos() < worldHeight - getWidth()) {
				setMoving(true);
				setFacing(right);
				movementCountdown = 2;
			}
		}

		if (*action == PlayerLeft)
		{
			if (getXPos() > 0) {

				setMoving(true);
				setFacing(left);
				movementCountdown = 2;
			}
		}



		if (*action == PlayerUp)
		{
			if (getYPos() > 0) {

				setMoving(true);
				setFacing(up);
				movementCountdown = 2;
			}
		}

		if (*action == PlayerDown)
		{
			if (getYPos() < worldHeight - getHeight()) {

				setMoving(true);
				setFacing(down);
				movementCountdown = 2;
			}
		}

	}
}
bool PlayerEntity::handleCollision() {
	for (Entity* entity : collisions) {

		if (entity->getType() == clown || entity->getType() == zombie) {
			setMoving(false);
			movementCountdown = 0;
		}
	}
	collisions.clear();
	return false;
}

float PlayerEntity::getAttackRange()
{
	return this->attackRange;
}

void PlayerEntity::setAttackRange(float attackRange)
{
	this->attackRange = attackRange;
}