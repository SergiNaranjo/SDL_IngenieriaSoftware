#pragma once

#include "Vector2.h"
#include "Renderer.h"
#include "Transform.h"
#include "RigidBody.h"
#include <string>
#include <SDL3/SDL.h>

class Object
{
private:
	bool _isPendingDestroy = false;
protected:
	RigidBody* _physics;
	Transform* _transform;
	Renderer* _renderer = nullptr;

public:
	Object() 
	{ 
		_transform = new Transform();
		_physics = new RigidBody(_transform);
	}

	~Object()
	{
		delete _transform;
		delete _renderer;
		delete _physics;
	}

	virtual void Update() 
	{ 
		if (_physics != nullptr)
		{
			_physics->Update(0.02f);
		}

		_renderer->Update(0.02f);
	}

	RigidBody* GetRigidBody() 
	{ 
		return _physics; 
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
};