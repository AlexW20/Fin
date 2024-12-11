#include "enemyEntity.h"
#include "world.h"
#include "playerEntity.h"
#include <raylib.h>
using namespace std;

EnemyEntity::EnemyEntity(float x, float y, int width, int height, EntityType type, string playerName, float health, Entity* playerToAttack) :Entity(x, y, width, height, type, playerName) {
	setHealth(health);
	setMaxHealth(health);
	movementCountdown = 2;
	this->playerToAttack = playerToAttack;
	this->primaryDirection = GetRandomValue(0, 1);
	PubSub::subscribe("action", this);
}

EnemyEntity::~EnemyEntity()
{
	PubSub::unsubscribe("action", this);
	PubSub::unsubscribe("entity", this);
}

void EnemyEntity::tick()
{

	if (movementCountdown != 0 && stunnedCountdown == 0) {
		if (playerToAttack->getYPos() < this->getYPos() - 4) {
			if (getYPos() > 0) {
				targetX = getXPos();
				targetY = getYPos() - 1;
				setSpeedX(0);
				setSpeedY(-1);
				setMoving(true);
				setFacing(up);
				movementCountdown = 2;
			}
		}
		
		else if (playerToAttack->getYPos() > this->getYPos() + 4) {
			if (getYPos() < worldHeight - getHeight()) {
				targetX = getXPos();
				targetY = getYPos() + 1;
				setSpeedX(0);
				setSpeedY(1);
				setMoving(true);
				setFacing(down);
				movementCountdown = 2;
			}
		}
		
		else if (playerToAttack->getXPos() < this->getXPos() - 4) {
			if (getXPos() > 0) {
				targetX = getXPos() - 1;
				targetY = getYPos();
				setSpeedX(-1);
				setSpeedY(0);
				setMoving(true);
				setFacing(left);
				movementCountdown = 2;
			}
		}
		
		else if (playerToAttack->getXPos() > this->getXPos() + 4) {
			if (getXPos() < worldWidth - getWidth()) {
				targetX = getXPos() + 1;
				targetY = getYPos();
				setSpeedX(1);
				setSpeedY(0);
				setMoving(true);
				setFacing(right);
				movementCountdown = 2;
			}
		}
	}
	else {
		if (stunnedCountdown != 0) {
			stunnedCountdown--;
			movementCountdown = -1;
		}
	}



	if (movementCountdown > 0)
	{

		movementCountdown--;

		if (movementCountdown == 0)
		{
			setMoving(false);
			setXPos(targetX);
			setYPos(targetY);

		}
		else
		{
			setXPos(getXPos() + getSpeedX());
			setYPos(getYPos() + getSpeedY());

		}
	}
}

void EnemyEntity::receiveMessage(string channel, string message, void* data) {
	if (channel == "action" && message == "attack") {
		Entity* entity = (Entity*)data;
		if (entity->getType() == Hunter) {
			PlayerEntity* attacker = (PlayerEntity*)entity;
			Rectangle thisEntityRectangle = { getXPos(),getYPos(),getWidth(), getHeight() };
			Rectangle attackerRectangle{};
			switch (attacker->getFacing()) {
			case right:
				attackerRectangle = { attacker->getXPos() + attacker->getWidth(),attacker->getYPos(),attacker->getAttackRange(),(float)attacker->getHeight() };
				break;
			case left:
				attackerRectangle = { attacker->getXPos() - attacker->getAttackRange(),attacker->getYPos(),attacker->getAttackRange(),(float)attacker->getHeight() };
				break;
			case up:
				attackerRectangle = { attacker->getXPos(), attacker->getYPos() - attacker->getAttackRange(),(float)attacker->getWidth(),attacker->getAttackRange() };
				break;
			case down:
				attackerRectangle = { attacker->getXPos(), attacker->getYPos() + attacker->getHeight(),(float)attacker->getWidth(),attacker->getAttackRange() };
				break;
			}
			if (CheckCollisionRecs(thisEntityRectangle, attackerRectangle)) {
				setHealth(getHealth() - attacker->getPower());

			}
		}
	}
}

bool EnemyEntity::handleCollision() {

	for (Entity* entity : collisions) {
		if (entity->getType() == Hunter && stunnedCountdown == 0) {
			PubSub::publish("entity", "hit", entity);
			stunnedCountdown = 90;
		}

	}
	collisions.clear();
	return false;
}