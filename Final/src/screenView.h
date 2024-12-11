#ifndef WORLDVIEW_H
#define WORLDVIEW_H

#include "raylib.h"
#include "world.h";
#include "PowerUps/powerUps.h"

class ScreenView
{
private:
	Texture2D background;
	int width, height;
	vector<PowerUps*> powerUpsArray;

public:
	ScreenView(vector<PowerUps*> powerUpsArray);
	void drawBackground(int viewportX, int viewportY, int viewportWidth, int viewportHeight);
	void draw(int coins, int worldLevel, int deletedEnemies, int viewportX, int viewportY, int viewportDrawX, int viewportDrawY, int viewportWidth, int viewportHeight);
	void deathScreenDraw(int worldLevel, int deletedEnemies, int viewportDrawX, int viewportDrawY, int viewportWidth, int viewportHeight);
	void drawIntroText(int step);
};



#endif