#include "particleView.h"
#include <map>

struct SpriteSheetInfo
{
    string fileName;
    int numFrames = 0;
    map<ParticleDirection, int> facings;
};
using namespace std;
map<ParticleType, SpriteSheetInfo> spriteMapping = {
    {
    attackParticle,
    {"resources/Particles/AttackParticles.png",9, {
        {up_direction, 0},
        {down_direction, 1},
        {left_direction, 2},
        {right_direction, 3}
}}
    }
};

ParticleView::ParticleView(Particles* particle)
{
    this->particle = particle;
    texture = Textures::loadTexture(spriteMapping[particle->getParticleType()].fileName);
    this->maxDuration = this->particle->getDuration();
    switch (particle->getParticlesEntity()->getFacing()) {
    case up:
        this->xCoordinate = this->particle->getXCoordinate() - this->particle->getParticlesEntity()->getWidth() / 2;
        this->yCoordinate = this->particle->getYCoordinate() - this->particle->getParticlesEntity()->getHeight() * 2;
        break;
    case down:
        this->xCoordinate = this->particle->getXCoordinate() - this->particle->getParticlesEntity()->getWidth() / 2;
        this->yCoordinate = this->particle->getYCoordinate() + this->particle->getParticlesEntity()->getHeight();
        break;
    case left:
        this->xCoordinate = this->particle->getXCoordinate() - this->particle->getParticlesEntity()->getWidth() * 2;;
        this->yCoordinate = this->particle->getYCoordinate() - (this->particle->getParticlesEntity()->getHeight() / 2);
        break;
    case right:
        this->xCoordinate = this->particle->getXCoordinate() + this->particle->getParticlesEntity()->getWidth();
        this->yCoordinate = this->particle->getYCoordinate() - this->particle->getParticlesEntity()->getHeight() / 2;;
        break;
    }
}

bool ParticleView::isViewFor(Particles* particle)
{
    return false;
}

void ParticleView::draw(int vx, int vy, int vdx, int vdy)
{
    int numFrames = spriteMapping[particle->getParticleType()].numFrames;


    int frameWidth = texture.width / numFrames;
    int row = spriteMapping[particle->getParticleType()].facings[particle->getParticleDirection()];

    if (particle->getDuration() > 0) {


        Rectangle srcRec = {
            (frame * frameWidth),
            (row * frameWidth),
            frameWidth ,
            frameWidth };

      
        Rectangle entityDestRec = {
           (this->xCoordinate - vx) + vdx,
           (this->yCoordinate - vy) + vdy,
            frameWidth * scale,    
            frameWidth * scale    
        };

        if (frame < numFrames) {
            DrawTexturePro(this->texture, srcRec, entityDestRec, { 0,0 }, 0, RAYWHITE);
        }

        particle->setDuration(particle->getDuration() - 1);
        
        if (particle->getDuration() % (this->maxDuration / numFrames) == 0) {
            if (frame != numFrames) {
                frame++;
            }
        }

    }
}