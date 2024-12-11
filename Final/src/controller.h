#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "pubsub.h"
#include "world.h"
#include "screen.h"
#include "entityView.h"
#include "Particles/particleView.h"
#include "screenView.h"
#include "textures.h";
#include "settings.h"

class Controller : public Subscriber {

private:
	World world;
	screenElements screen;
	vector<EntityView* > views;
	vector<ParticleView* > particleViews;

public:
	void gameLoop();
	void receiveMessage(string channel, string message, void* data);
};


#endif