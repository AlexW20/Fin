#ifndef SCREEN_H
#define SCREEN_H

#include "./PowerUps/powerUps.h"
#include <vector>;


class screenElements {
private:
	int coins = 0;
	int level = 0;
	vector<PowerUps*> powerUpsArray;
public:
	void setCoins(int coins);
	int getCoins();
	void setLevel(int level);
	int getLevel();
	void addPowerUp(PowerUpType type, int x, int y, int width, int height, int cost, int stationLevel);
	vector<PowerUps*> getPowerUps();
};



#endif