#include "screen.h"
#include "PowerUps/health.h"
#include "PowerUps/extendedRange.h"
#include "PowerUps/speed.h"
#include "PowerUps/power.h"

void screenElements::setCoins(int coins)
{
	this->coins = coins;
}

int screenElements::getCoins()
{
	return this->coins;
}

void screenElements::setLevel(int level)
{
	this->level = level;
}

int screenElements::getLevel()
{
	return this->level;
}

void screenElements::addPowerUp(PowerUpType type, int x, int y, int width, int height, int cost, int stationLevel)
{
	PowerUps* power;
	switch (type) {
	case healthType:
		power = new Health(x, y, width, height, type, cost, stationLevel);
		powerUpsArray.push_back(power);
		break;
	case speedType:
		power = new Speed(x, y, width, height, type, cost, stationLevel);
		powerUpsArray.push_back(power);
		break;
	case powerType:
		power = new Power(x, y, width, height, type, cost, stationLevel);
		powerUpsArray.push_back(power);
		break;
	case extendedRangeType:
		power = new ExtendedRange(x, y, width, height, type, cost, stationLevel);
		powerUpsArray.push_back(power);
		break;

	}
}

vector<PowerUps*> screenElements::getPowerUps()
{
	return powerUpsArray;
}