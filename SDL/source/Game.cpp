#include "Object.h"
#include "Game.h"
#include "ImageObject.h"
#include "TestObject.h"
#include "InputManager.h"

void Game::Init()
{
	RM->Init();
	RM->LoadTexture("resources/image.png");

	_gameObjects.push_back(new TestObject());
	_gameObjects.push_back(new TestObject());

	_isRunning = true;
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
	_isRunning = !IM->Listen();
}

void Game::Update()
{
	for (Object* go : _gameObjects)
	{
		go->Update();
	}
}

void Game::Render()
{
	RM->ClearScreen();

	for (Object* go : _gameObjects)
	{
		go->Render();
	}

	RM->RenderScreen();
}

void Game::Release()
{
	for (Object* go : _gameObjects)
	{
		delete go;
	}
	_gameObjects.clear();

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}
