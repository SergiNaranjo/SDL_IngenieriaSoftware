#include "Object.h"
#include "Game.h"
#include "ImageObject.h"
#include "TestObject.h"
#include "InputManager.h"

void Game::Init()
{
	RM->Init();

	RM->LoadTexture("resources/image.png");

	TestObject test1 = TestObject();
	_gameObjects.push_back(new ImageObject(test1));

	TestObject test2 = TestObject();
	_gameObjects.push_back(new ImageObject(test2));

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

	if (IM->GetEvent(SDLK_S, KeyState::DOWN))
	{
		SDL_SetRenderDrawColor(_renderer, 225, 0, 200, 0xFF);
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
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}
