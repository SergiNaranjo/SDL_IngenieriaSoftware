#pragma once

#include "Renderer.h"
#include "RenderManager.h"

class ImageRenderer : public Renderer
{
public:
	void LoadTexture(std::string texturePath, SDL_Renderer* renderer) override;
	void Update();
	void Render(SDL_Renderer* renderer);

	ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize) : Renderer(transform, resourcePath)
	{
		RM->GetTexture(resourcePath);

		_sourceRect = SDL_FRect
		{
			sourceOffset.x,
			sourceOffset.y,
			sourceSize.x,
			sourceSize.y
		};

		_destinationRect = SDL_FRect
		{
			transform->position.x,
			transform->position.y,
			transform->scale.x,
			transform->scale.y
		};
	}
};