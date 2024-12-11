#include "raylib.h"
#include "controller.h"

#include <math.h>

int main(void)
{

    Controller c;
    c.gameLoop();

    return 0;
}
int viewportWidth = 0;
int viewportHeight = 0;
int viewportX = 0;
int viewportY = 0;
int viewportDrawX;
int viewportDrawY = 0;

void Controller::gameLoop() {

    SetTargetFPS(60);
    map<KeyboardKey, userAction> keyMapping;

    keyMapping[KEY_W] = PlayerUp;
    keyMapping[KEY_A] = PlayerLeft;
    keyMapping[KEY_S] = PlayerDown;
    keyMapping[KEY_D] = PlayerRight;


    PubSub::subscribe("entity", this);
    PubSub::subscribe("particle", this);
    PubSub::subscribe("action", this);
    PubSub::subscribe("player", this);

    InitWindow(GetScreenWidth(), GetScreenHeight(), "ZombieHunter");
    InitAudioDevice();
   
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    ToggleFullscreen();





    viewportWidth = GetScreenWidth();
    viewportHeight = GetScreenHeight();
    world.addPlayer((worldWidth / 2) - 8, (worldHeight / 2) - 8, 16, 16, Hunter, "Hunter", 40);
    screen.addPowerUp(healthType, 10, 10, 32, 32, 10, 1);
    screen.addPowerUp(speedType, 10, 200, 32, 32, 10, 1);
    screen.addPowerUp(powerType, 10, 390, 32, 32, 10, 1);
    screen.addPowerUp(extendedRangeType, 10, 580, 32, 32, 10, 1);
    ScreenView screenView(screen.getPowerUps());
   
    int step = 1;
   
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            step++;
            if (step > 5) {
                break;
            }
        }
        BeginDrawing();
        screenView.drawBackground(viewportX, viewportY, viewportWidth, viewportHeight);
        screenView.drawIntroText(step);

        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    while (!WindowShouldClose() && world.getAliveState())
    {
        world.EnemyCount(10);
       

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            for (PowerUps* power : screen.getPowerUps()) {
                Rectangle hitPowerUp = {
                power->getXPos(),power->getYPos(),power->getWidth(),power->getHeight()
                };

                Vector2 mouse = GetMousePosition();
                if ((mouse.x > hitPowerUp.x) && (mouse.x < hitPowerUp.width + hitPowerUp.x) && (mouse.y > hitPowerUp.y) && (mouse.y < hitPowerUp.height + hitPowerUp.y)) {
                    if (power->getCost() <= world.getCoins()) {
                        world.setCoins(world.getCoins() - power->getCost());
                        PubSub::publish("power_up", "buy", power);
                        power->setLevel(power->getLevel() + 1);
                        power->setCost(power->getCost() * 1.5);
                    }
                }
            }


        }
       

        if (IsKeyPressed(KEY_SPACE)) {
            userAction action = PlayerHit;
            PubSub::publish("action", "player", &action);
        }
        for (auto& i : keyMapping)
        {
            if (IsKeyDown(i.first))
            {
                userAction action = i.second;
                PubSub::publish("action", "player", &action);
            }
        }


       
        world.tick();

        BeginDrawing();
        screenView.drawBackground(viewportX, viewportY, viewportWidth, viewportHeight);

  
        for (EntityView* view : views)
            view->draw(viewportX, viewportY, viewportDrawX, viewportDrawY, viewportWidth, viewportHeight);
        for (ParticleView* pView : particleViews) {
            pView->draw(viewportX, viewportY, viewportDrawX, viewportDrawY);
        }

        screenView.draw(world.getCoins(), world.getWorldLevel(), world.getDeletedEnemiesCount(), viewportX, viewportY, viewportDrawX, viewportDrawY, viewportWidth, viewportHeight);

        EndDrawing();


    }
    while (!WindowShouldClose() && world.getAliveState() == false) {

      
        screenView.deathScreenDraw(world.getWorldLevel(), world.getDeletedEnemiesCount(), viewportDrawX, viewportDrawY, viewportWidth, viewportHeight);
        BeginDrawing();

        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    world.clearWorld();


    CloseWindow();
}

void Controller::receiveMessage(string channel, string message, void* data)
{
    if (channel == "action" && message == "attack") {
        Entity* entity = (Entity*)data;
        world.addParticle(attackParticle, entity->getXPos(), entity->getYPos(), entity, 20);
    }
    if (channel == "player" && message == "location")
    {
        Vector2* position = (Vector2*)data;
        if ((position->x - viewportWidth / 2) >= 0 && position->x + viewportWidth / 2 <= worldWidth) {
            viewportX = position->x - viewportWidth / 2;

        }
        if ((position->y - viewportHeight / 2) >= 0 && position->y + viewportHeight / 2 <= worldHeight) {
            viewportY = position->y - viewportHeight / 2;
        }
    }
    if (channel == "entity" && message == "hit") {
        Entity* entity = (Entity*)data;
        entity->setHealth(entity->getHealth() - (2 * world.getWorldLevel()));
    }
   

    if (channel == "entity" && message == "new")
    {
       
        EntityView* view = new EntityView((Entity*)data);
        views.push_back(view);
    }

    if (channel == "particle" && message == "new")
    {
      
        ParticleView* view = new ParticleView((Particles*)data);
        particleViews.push_back(view);
    }

    if (channel == "entity" && message == "delete")
    {




       
        for (int i = 0; i < views.size(); i++)
        {


            if (views[i]->isViewFor((Entity*)data))
            {
                delete views[i];
               
                views.erase(views.begin() + i);
              
                break;
            }
        }

        Entity* entity = (Entity*)data;
        if (entity->getType() == Hunter) {
            world.setAliveState(false);
            return;
        }





        if (channel == "particle" && message == "delete")
        {




            for (int i = 0; i < particleViews.size(); i++)
            {


                if (particleViews[i]->isViewFor((Particles*)data))
                {
                    delete particleViews[i];
                    
                    particleViews.erase(particleViews.begin() + i);
                    
                    break;
                }
            }
        }

        world.setCoins(world.getCoins() + GetRandomValue(3, 5));

        world.increaseDeletedEnemies(1);
    }
}