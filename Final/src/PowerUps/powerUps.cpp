#include "powerUps.h"


#include <map>

map<PowerUpType, string> textureArray = {
	{healthType, "resources/HealthIcon.png"},
	{speedType, "resources/SpeedIcon.png"},
	{powerType, "resources/PowerIcon.png"},
	{extendedRangeType, "resources/ExtendedRange.png"}
};

PowerUps::PowerUps(PowerUpType put, float xPosition, float yPosition, float width, float height)
{
	this->type = put;
	this->xPosition = xPosition;
	this->yPosition = yPosition;
	this->width = width * hudScale;
	this->height = height * hudScale;
	this->texture = Textures::loadTexture(textureArray[put]);
}
bool PowerUps::isViewFor(PowerUpType* put)
{
	return false;
}

float PowerUps::getYPos()
{
	return this->yPosition;
}

float PowerUps::getWidth()
{
	return this->width;
}

Texture2D PowerUps::getTexture() {
	return this->texture;
}

float PowerUps::getHeight()
{
	return this->width;
}

float PowerUps::getXPos()
{
	return this->xPosition;
}

void PowerUps::setCost(int cost)
{
	this->cost = cost;
}

int PowerUps::getCost()
{
	return this->cost;
}

void PowerUps::setLevel(int level)
{
	this->level = level;
}
PowerUpType PowerUps::getType() {
	return this->type;
}
int PowerUps::getLevel()
{
	return this->level;
}

