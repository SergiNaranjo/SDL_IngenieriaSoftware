#include "GameObject.h"
#include "Game.h"

void Game::Init()
{
	InitSDL();
	CreateWindowAndRenderer();

	SDL_SetRenderDrawColor(_renderer, 0, 200, 180, 0xFF);

	_isRunning = true;

	_gameObjects.push_back(GameObject("resources/image.png", _renderer));
}

void Game::InitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		throw SDL_GetError();
	}
}

void Game::CreateWindowAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer("JIJIJIJA", 512, 512, SDL_WINDOW_RESIZABLE, &_window, &_renderer))
	{
		throw SDL_GetError;
	}
}

void Game::HandelEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			_isRunning = false;
		}
	}
}

void Game::Update()
{
	for (GameObject go : _gameObjects)
	{
		go.Update();
	}
}

void Game::Render()
{
	SDL_RenderClear(_renderer);

	for (GameObject go : _gameObjects)
	{
		go.Render(_renderer);
	}

	SDL_RenderPresent(_renderer);
}

void Game::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}
