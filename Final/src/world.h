#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "entity.h"
#include "Particles/particles.h"
using namespace std;

enum userAction { CreateEnemy, PlayerUp, PlayerDown, PlayerRight, PlayerLeft, PlayerHit };

class World
{
private:
	vector<Entity*> entities;
	vector<Particles*> particles;
	vector<Entity*> collisions;
	vector<Entity*> deletions;
	void checkCollision(Entity* entity, Entity* entity2);
	int worldLevel = 0;
	int deletedEnemiesCount = 0;
	bool stillAlive = true;

public:
	int level = 1;
	int coins = 0;
	World();
	void EnemyCount(int enemyBaseHealth);
	void clearWorld();
	void addEntity(int x, int y, int width, int height, EntityType type, string EntityName);
	void setWorldLevel(int worldLevel);
	int getWorldLevel();
	void addPlayer(int x, int y, int width, int height, EntityType type, string playerName, float health);
	void addEnemy(int x, int y, int width, int height, EntityType type, string playerName, float health);
	vector<Entity*> getWorldEntities();
	void tick();
	void increaseDeletedEnemies(int number);
	int getDeletedEnemiesCount();
	void setCoins(int coinNumber);
	int getCoins();
	bool getAliveState();
	void setAliveState(bool stillAlive);
	void addParticle(ParticleType particleType, float xCoordinate, float yCoordinate, Entity* entity, float duration);
};

#endif