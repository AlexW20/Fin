#ifndef ENEMYENTITY_H
#define ENEMYENTITY_H

#include "entity.h"
#include "pubsub.h"

using namespace std;

class EnemyEntity : public Entity, public Subscriber {

private:
	float targetX, targetY;
	int movementCountdown = 2;
	int stunnedCountdown = 0;
	float enemySpeedX, enemySpeedY; 
	Entity* playerToAttack;
	int primaryDirection;
public:
	EnemyEntity(float x, float y, int width, int height, EntityType type, string playerName, float health, Entity* playerToAttack);
	~EnemyEntity();
	void tick();
	void receiveMessage(string channel, string name, void* data);
	bool handleCollision();
};



#endif