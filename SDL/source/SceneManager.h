#pragma once

#include "Scene.h"

#include <unordered_map>
#include <string>

#define SM SceneManager::Instance()

class SceneManager
{
private:
	std::unordered_map<std::string, Scene*> _scene;
	Scene* _currentScene = nullptr;
	std::string _nextScene = "";

	SceneManager() = default;
	SceneManager(SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

public:
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}

	bool AddScene(std::string name, Scene* scene)
	{
		if (_scene.find(name) == _scene.end())
		{
			_scene.emplace(name, scene);
			return true;
		}

		return false;
	}

	Scene* GetScene(std::string name)
	{
		if (_scene.find(name) != _scene.end())
		{
			return _scene[name];
		}

		return nullptr;
	}

	bool InitFirstScene(std::string name)
	{
		if (_scene.find(name) != _scene.end())
		{
			_currentScene = _scene[name];
			_currentScene->OnEnter();
			return true;
		}

		return false;
	}

	inline Scene* GetCurrentScene() const { return _currentScene; }

	bool SetNextScene(std::string name)
	{
		if (_scene.find(name) == _scene.end())
		{
			return false;
		}

		_nextScene = name;
		return true;
	}

	void UpdateCurrentScene()
	{
		if (_nextScene != "")
		{
			_currentScene->OnExit();
			_currentScene = _scene[_nextScene];
			_currentScene->OnEnter();
			_nextScene = "";
		}

		_currentScene->Update();
	}
};