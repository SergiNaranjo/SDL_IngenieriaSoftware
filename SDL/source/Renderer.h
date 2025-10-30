#pragma once

#include <SDL3/SDL.h>
#include <string>

class Renderer
{
protected:
	SDL_Texture* _texture;
	SDL_FRect _sourceRect;
	SDL_FRect _destinationRect;

public:
	virtual void LoadTexture(std::string texturePath, SDL_Renderer* renderer) = 0;
	virtual void Update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void SetDestinationRect(SDL_FRect rect)
	{
		_destinationRect = rect;
	}
};