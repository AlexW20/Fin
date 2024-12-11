#ifndef PARTICLES_H
#define PARTICLES_H

#include "settings.h"
#include "raylib.h"
#include <vector>
#include <string>
#include "entity.h"


using namespace std;

enum ParticleType {
	attackParticle
};
enum ParticleDirection {
	left_direction,
	right_direction,
	up_direction,
	down_direction
};
class Particles {
protected:
	ParticleType particleType;
	float xCoordinate, yCoordinate;
	Entity* entity;
	ParticleDirection particleDirection;
	int duration;
public:
	Particles(ParticleType particleType, float xCoordinate, float yCoordinate, Entity* entity, float duration);
	float getXCoordinate();
	float getYCoordinate();
	ParticleType getParticleType();
	Entity* getParticlesEntity();
	ParticleDirection getParticleDirection();
	int getDuration();
	void setDuration(float duration);
};
#endif 