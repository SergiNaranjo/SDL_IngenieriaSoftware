#pragma once

#include "Scene.h"
#include "TestObject.h"
#include "TextObject.h"
#include "AudioManager.h"


class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override
	{
		SPAWNER.SpawnObject(new TestObject());
		SPAWNER.SpawnObject(new TestObject());

		TextObject* text = new TextObject("JIJIJIJA");
		text->GetTransform()->position = { 100.f, 100.f };
		_ui.push_back(text);

		AM->PlaySound("resources/audio/sfx/defeat.wav");
		AM->PlaySound("resources/audio/music/froggerSong.wav");
	}

	void OnExit() override { Scene::OnExit(); }
	
	void Update() override { Scene::Update(); }

	void Render() override { Scene::Render(); }
};