#include "pch.h"
#include "Game.h"
#include "Graphics.h"
#include "GameObject.h"
#include "Camera.h"
#include "MeshRenderer.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(HWND hwnd)
{
	_hwnd = hwnd;
	
	_graphics = make_shared<Graphics>(hwnd);
	_pipeline = make_shared<Pipeline>(_graphics->GetDeviceContext());

	//GameObject
	_gameObject = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	{
		_gameObject->GetOrAddTransform();
		_gameObject->AddComponent(make_shared<MeshRenderer>(_graphics->GetDevice(),_graphics->GetDeviceContext()));
		_gameObject->GetTransform()->SetScale(Vec3(100.f, 100.f, 1.f));
	}

	_camera = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	{
		_camera->GetOrAddTransform();
		_camera->AddComponent(make_shared<Camera>());
	}
}

void Game::Update()
{
	_gameObject->Update();
	_camera->Update();
}

void Game::Render()
{
	_graphics->RenderBegin();

	// IA - VS - RS - PS - OM
	{
		_gameObject->GetMeshRenderer()->Render(_pipeline);
	}

	_graphics->RenderEnd();
}
