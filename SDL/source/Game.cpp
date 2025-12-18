#include "Object.h"
#include "Game.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include "MainMenu.h"
#include "AudioManager.h"

void Game::Init()
{
	AM->Init();
	RM->Init();
	RM->LoadTexture("resources/image.png");
	RM->LoadFont(FONT_PATH);
	AM->LoadSoundData("resources/audio/sfx/defeat.wav");
	AM->LoadSoundData("resources/audio/music/froggerSong.wav");


	assert(SM.AddScene("MainMenu", new MainMenu()));
	assert(SM.AddScene("Gameplay", new Gameplay()));
	assert(SM.InitFirstScene("MainMenu"));

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
	SM.UpdateCurrentScene();
}

void Game::Render()
{
	RM->ClearScreen();
	SM.GetCurrentScene()->Render();
	RM->RenderScreen();
}

void Game::Release()
{
	RM->Release();
	AM->HaltAudio();
	SDL_Quit();
}

bool Game::IsRunning() const
{
	return _isRunning;
}
