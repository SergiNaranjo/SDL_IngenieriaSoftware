#pragma once

#include "Scene.h"
#include "Button.h"
#include "SceneManager.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;

	void OnEnter() override
	{
		Button* button = new Button([]() {
			SM.SetNextScene("Gameplay");
			});

		_ui.push_back(button);
	}

	void OnExit() override
	{
		Scene::OnExit();
	}

	void Update() override
	{
		Scene::Update();
	}

	void Render() override
	{
		Scene::Render();
	}
};