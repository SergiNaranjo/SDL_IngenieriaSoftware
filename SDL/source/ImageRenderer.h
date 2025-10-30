#pragma once

#include "Renderer.h"

class ImageRenderer : public Renderer
{
public:
	void LoadTexture(std::string texturePath, SDL_Renderer* renderer) override;
	void Update();
	void Render(SDL_Renderer* renderer);
};