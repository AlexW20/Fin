#ifndef ENTITY_H
#define ENTITY_H

#include "settings.h"
#include <vector>
#include <string>
using namespace std;

enum EntityType {
	Hunter,
	portal,
	zombie,
	clown,
	Range,
	health,
	power,
	speed
};
enum EntityFacing { up, down, left, right };

class Entity
{
private:
	float maxHealth = -1;
	float currentHealth = -1;
	float xPos;
	float yPos;
	int width;
	int height;
	EntityType type;
	EntityFacing facing;
	bool moving;

	string entityName;
	int level = -1;
	float power;
	float speedX, speedY;
protected:
	vector<Entity* > collisions;
	Entity* player;
	int price = -1;
public:
	Entity(float x, float y, int width, int height, EntityType type, string entityName, float maxHealth = -1, EntityFacing facing = EntityFacing::right);
	virtual ~Entity();
	float getXPos();
	float getYPos();
	int getLevel();
	void setLevel(int level);
	void setPrice(int price);
	float getSpeedX();
	float getSpeedY();
	void setSpeedX(float speedX);
	void setSpeedY(float speedY);
	int getPrice();
	void setPower(float power);
	float getPower();
	void setHealth(float currentHealth);
	void setMaxHealth(float maxHealth);
	float getHealth();
	float getMaxHealth();
	string getEntityName();
	int getWidth();
	int getHeight();
	EntityType getType();
	virtual EntityFacing getFacing();
	bool getMoving();

	void setXPos(float x);
	void setYPos(float y);
	void setFacing(EntityFacing facing);
	void setMoving(bool moving);

	virtual void tick();

	
	void addCollision(Entity* entity);
	virtual bool handleCollision();
};
#endif