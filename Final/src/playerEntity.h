#ifndef LASEREYEENTITY_H
#define LASEREYEENTITY_H

#include "entity.h"
#include "pubsub.h"

using namespace std;

class PlayerEntity : public Entity, public Subscriber {

private:
	float targetX, targetY;
	int movementCountdown;
	float attackRange = playerHitRange;
public:
	~PlayerEntity();
	PlayerEntity(float x, float y, int width, int height, EntityType type, string playerName, float health);
	void tick();
	void receiveMessage(string channel, string name, void* data);
	bool handleCollision();
	float getAttackRange();
	void setAttackRange(float attackRange);
};



#endif