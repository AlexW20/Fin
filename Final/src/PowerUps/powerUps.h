#ifndef POWERUPS_H
#define POWERUPS_H
#include <./raylib.h>
#include "./world.h"
#include "./textures.h"

enum PowerUpType {
	healthType,
	speedType,
	powerType,
	extendedRangeType,
};

class PowerUps
{
private:
	Texture2D texture;
	int frame;
	int delay;
	float xPosition, yPosition;
	float width, height;
	int level;
	int cost;
protected:

	int maxCoolDown = 60;
	int coolDown = 60;
	PowerUpType type;

public:
	PowerUps(PowerUpType put, float xPosition, float yPosition, float width, float height);
	bool isViewFor(PowerUpType* put);
	PowerUpType getType();
	float getXPos();
	float getYPos();
	float getWidth();
	float getHeight();
	string getName();
	Texture2D getTexture();
	void setCost(int cost);
	int getCost();
	void setLevel(int level);
	int getLevel();
};


#endif;