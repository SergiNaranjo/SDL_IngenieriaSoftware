#pragma once

#include "Vector2.h"
#include "Renderer.h"
#include "Transform.h"
#include <string>
#include <SDL3/SDL.h>

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Transform* _transform;
	Renderer* _renderer = nullptr;

public:
	Object() 
	{ 
		_transform = new Transform();
	}

	virtual void Update() 
	{ 
		_renderer->Update(0.02f);
	}

	virtual void Render() 
	{ 
		_renderer->Render(); 
	}

	Transform* GetTransform()
	{
		return _transform;
	}

	bool IsPendingDestroy() const
	{
		return _isPendingDestroy;
	}

	virtual void Destroy()
	{
		_isPendingDestroy = true;
	}

	/*~Object()
	{
		delete _transform;
		_transform = nullptr;

		delete _renderer;
		_renderer = nullptr;
	}*/
};