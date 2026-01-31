#include "pch.h"
#include "Game.h"
#include "Graphics.h"
#include "GameObject.h"
#include "Camera.h"
#include "MeshRenderer.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "ResourceManager.h"

unique_ptr<Game> GGame = make_unique<Game>();

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

	_scene = make_shared<SceneManager>(_graphics);
	_scene->Init();
	_input = make_shared<InputManager>();
	_input->Init(hwnd);
	_time = make_shared<TimeManager>();
	_time->Init();
	_resource = make_shared<ResourceManager>(_graphics->GetDevice());
	_resource->Init();

	SCENE->LoadScene(L"Test");
}

void Game::Update()
{
	_graphics->RenderBegin();
	TIME->Update();
	INPUT->Update();
	SCENE->Update();
	_graphics->RenderEnd();
}

void Game::Render()
{
	_graphics->RenderBegin();

	// IA - VS - RS - PS - OM
	{
	}

	_graphics->RenderEnd();
}
