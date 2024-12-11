#include "screenView.h"
#include "textures.h"
#include "raylib.h"
#include <string>

ScreenView::ScreenView(vector<PowerUps*> powerUpsArray)
{
    this->background = Textures::loadTexture("resources/streets.png");
    this->width = background.width;
    this->height = background.height;
    this->powerUpsArray = powerUpsArray;
}

void ScreenView::drawBackground(int viewportX, int viewportY, int viewportWidth, int viewportHeight) {


    // Source rectangle: part of the texture to be drawn (the specific frame)
    Rectangle srcRec = { viewportX, viewportY,viewportWidth,viewportHeight };


    // Destination rectangle: where to draw the sprite on screen (with scaling)
    Rectangle destRec = { 0,0, viewportWidth, viewportHeight };



    // Draw the texture region to the screen using the destination rectangle
    //Draw Player Name

    //Draw Entity Texture
    DrawTexturePro(background, srcRec, destRec, { 0,0 }, 0.0f, WHITE);

}
void ScreenView::draw(int coins, int worldLevel, int deletedEnemies, int viewportX, int viewportY, int viewportDrawX, int viewportDrawY, int viewportWidth, int viewportHeight) {


    string coinText = "Coins: " + std::to_string(coins);
    string levelText = "Level " + std::to_string(worldLevel);
    string enemiesKilled = "Enemies Killed: " + std::to_string(deletedEnemies);
    DrawRectangle(viewportWidth - 320, 5, 300, 120, { 255,255,255,200 });
    DrawText(levelText.c_str(), (viewportWidth)-300, 10, 50, BROWN);
    DrawText(coinText.c_str(), (viewportWidth)-300, 60, 30, DARKGRAY);
    DrawText(enemiesKilled.c_str(), (viewportWidth)-300, 90, 30, { 20,20,20,255 });

    //Drawing powerups
    for (int i = 0; i < powerUpsArray.size(); i++) {

        if (hitbox) {
            DrawRectangle(powerUpsArray[i]->getXPos(), powerUpsArray[i]->getYPos(), powerUpsArray[i]->getWidth(), powerUpsArray[i]->getHeight(), RED);

        }
        DrawTexturePro(powerUpsArray[i]->getTexture(), { 0,0,32,32 }, { powerUpsArray[i]->getXPos(),powerUpsArray[i]->getYPos(),powerUpsArray[i]->getWidth(),powerUpsArray[i]->getHeight() }, { 0, 0 }, 0.0f, WHITE);
        //the powerup level and price of station
        int fontSize = 6 * hudScale;
        string levelText = "lvl. " + to_string((powerUpsArray[i]->getLevel()));
        string costText = "$" + to_string(powerUpsArray[i]->getCost());
        DrawText((costText + " " + levelText).c_str(), powerUpsArray[i]->getXPos(), powerUpsArray[i]->getYPos() + powerUpsArray[i]->getHeight() + (fontSize / 2.5) + 10, fontSize, WHITE);
    }
}

void ScreenView::deathScreenDraw(int worldLevel, int deletedEnemies, int viewportDrawX, int viewportDrawY, int viewportWidth, int viewportHeight) {

    // Source rectangle: part of the texture to be drawn (the specific frame)
    Rectangle srcRec = { 0,0,width,height };


    // Destination rectangle: where to draw the sprite on screen (with scaling)
    Rectangle destRec = { viewportDrawX, viewportDrawY, viewportWidth, viewportHeight };


    // Draw the texture region to the screen using the destination rectangle
    //Draw Player Name

    //Draw Entity Texture
    DrawTexturePro(background, srcRec, destRec, { 0, 0 }, 0.0f, GRAY);
    string levelText = "You made it to level " + std::to_string(worldLevel);
    string enemiesKilled = "Enemies Killed: " + std::to_string(deletedEnemies);
    DrawText(levelText.c_str(), viewportWidth / 4, viewportHeight / 4, 100, WHITE);
    DrawText(enemiesKilled.c_str(), viewportWidth / 4, viewportHeight / 2, 100, WHITE);


}

void ScreenView::drawIntroText(int step) {
    string s = "";
    switch (step) {
    case 1:
        s = "You are Deadpool, you are tasked with killing all the zombies and clowns";
        break;
    case 2:
        s = "Use W, A, S, D keys to move around";
        break;
    case 3:
        s = "Use space bar to hit zombies";
        break;
    case 4:
        s = "Use coins to power up your player. You get coins from killing enemies!";
        break;
    case 5:
        s = "Good Luck!";
        break;
    }
    DrawRectangle(20, 20, GetScreenWidth() - 40, 170, WHITE);
    DrawText(s.c_str(), 40, 50, 50, RED);
    string sp = "(Use space bar to continue.)";
    DrawText(sp.c_str(), 40, 100, 50, BLACK);


}