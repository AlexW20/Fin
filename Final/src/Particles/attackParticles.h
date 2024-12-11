#ifndef ATTACK_PARTICLES_H
#define ATTACK_PARTICLES_H

#include "particles.h"
#include "../pubsub.h"

using namespace std;

class AttackParticles : public Particles, public Subscriber {

private:
	float targetX, targetY;
	int movementCountdown = 2;
	int stunnedCountdown = 0;
	float enemySpeedX, enemySpeedY; 
	Entity* playerToAttack;
	int primaryDirection;
public:
	AttackParticles(ParticleType particleType, float xCoordinate, float yCoordinate, Entity* entity, float duration);
	~AttackParticles();
	void tick();
	void receiveMessage(string channel, string name, void* data);
	bool handleCollision();
};



#endif