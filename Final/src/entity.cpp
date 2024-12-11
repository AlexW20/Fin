#include "entity.h"
#include <string>
using namespace std;


Entity::Entity(float x, float y, int width, int height, EntityType type, string entityName, float health, EntityFacing facing) {
	this->xPos = x;
	this->yPos = y;
	this->width = width * scale;
	this->height = height * scale;
	this->type = type;
	this->facing = facing;
	this->moving = false;
	this->entityName = entityName;
	this->maxHealth = health;
	this->power = -1;
}

Entity::~Entity()
{
}


float Entity::getXPos() {
	return this->xPos;
}

float Entity::getYPos() {
	return this->yPos;
}
int Entity::getLevel()
{
	return this->level;
}
void Entity::setLevel(int level) {
	this->level = level;
}
void Entity::setPrice(int price) {
	this->price = price;
}
float Entity::getSpeedY()
{
	return this->speedY;
}
float Entity::getSpeedX()
{
	return this->speedX;
}

void Entity::setSpeedY(float speedY)
{
	this->speedY = speedY;
}
void Entity::setSpeedX(float speedX)
{
	this->speedX = speedX;
}


int Entity::getPrice() {
	return this->price;
}
void Entity::setPower(float power)
{
	this->power = power;
}
float Entity::getPower() {
	return this->power;
}
void Entity::setHealth(float currentHealth)
{
	this->currentHealth = currentHealth;
}
void Entity::setMaxHealth(float maxHealth)
{
	this->maxHealth = maxHealth;
}
float Entity::getHealth()
{
	return this->currentHealth;
}
float Entity::getMaxHealth()
{
	return this->maxHealth;
}
string Entity::getEntityName() {
	return this->entityName;
}
int Entity::getWidth() {
	return this->width;
}
int Entity::getHeight() {
	return this->height;
}
EntityType Entity::getType() {
	return this->type;
}
EntityFacing Entity::getFacing() {
	return this->facing;
}
bool Entity::getMoving() {
	return this->moving;
}
void Entity::setXPos(float x) {
	this->xPos = x;
}
void Entity::setYPos(float y) {
	this->yPos = y;
}
void Entity::setFacing(EntityFacing facing) {
	this->facing = facing;
}
void Entity::setMoving(bool moving) {
	this->moving = moving;
}
void Entity::tick() {
}

void Entity::addCollision(Entity* entity) {
	collisions.push_back(entity);
}

bool Entity::handleCollision() {
	return false;
}