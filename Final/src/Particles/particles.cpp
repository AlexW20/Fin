#include "particles.h"

Particles::Particles(ParticleType particleType, float xCoordinate, float yCoordinate, Entity* entity, float duration)
{
	this->particleType = particleType;
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
	this->entity = entity;
	this->duration = duration;
	switch (entity->getFacing()) {
	case up:
		this->particleDirection = up_direction;
		break;
	case down:
		this->particleDirection = down_direction;
		break;
	case left:
		this->particleDirection = left_direction;
		break;
	case right:
		this->particleDirection = right_direction;
	}
}

float Particles::getXCoordinate()
{
	return this->xCoordinate;
}

float Particles::getYCoordinate()
{
	return this->yCoordinate;
}

ParticleType Particles::getParticleType()
{
	return this->particleType;
}

Entity* Particles::getParticlesEntity()
{
	return this->entity;
}

ParticleDirection Particles::getParticleDirection()
{
	return this->particleDirection;
}

int Particles::getDuration()
{
	return this->duration;
}
void Particles::setDuration(float duration) {
	this->duration = duration;
}