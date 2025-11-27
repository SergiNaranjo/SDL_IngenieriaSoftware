#pragma once

#include "Scene.h"
#include "TestObject.h"
#include "TextObject.h"


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
	}

	void OnExit() override { Scene::OnExit(); }
	
	void Update() override { Scene::Update(); }

	void Render() override { Scene::Render(); }
};