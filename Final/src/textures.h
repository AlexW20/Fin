#ifndef TEXTURES_H
#define TEXTURES_H

#include <map>
#include <string>
#include "raylib.h"

using namespace std;

class Textures
{
private:
	static map<string, Texture2D> textures;
	static map<string, Image> images;

public:
	static Texture2D loadTexture(string file);
	static Image loadImage(string file);
};

#endif