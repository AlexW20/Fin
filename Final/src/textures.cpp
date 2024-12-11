#include <algorithm>
#include "textures.h"
#include <iostream>

using namespace std;

map<string, Texture2D> Textures::textures;
map<string, Image> Textures::images;


Texture2D Textures::loadTexture(string file)
{
	cout << "Trying to load " << file.c_str();
	if (textures.find(file) == textures.end())
	{
		Texture2D texture = LoadTexture(file.c_str());
		textures[file] = texture;
	}

	return textures[file];
}

Image Textures::loadImage(string file)
{
	cout << "Trying to load " << file.c_str();
	if (images.find(file) == images.end())
	{
		Image image = LoadImage(file.c_str());
		images[file] = image;
	}

	return images[file];
}