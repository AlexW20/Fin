#include "attackParticles.h"

AttackParticles::AttackParticles(ParticleType particleType, float xCoordinate, float yCoordinate, Entity* entity, float duration) :Particles(particleType, xCoordinate, yCoordinate, entity, duration)
{
	PubSub::subscribe("action", this);

}

AttackParticles::~AttackParticles()
{
	PubSub::unsubscribe("action", this);

}

void AttackParticles::tick()
{
	if (duration == 0) {
		PubSub::publish("particle", "delete", this);

	}
	duration--;
}

void AttackParticles::receiveMessage(string channel, string name, void* data)
{
}

bool AttackParticles::handleCollision()
{
	return false;
}