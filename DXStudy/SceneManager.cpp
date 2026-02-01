#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"
#include "MeshRenderer.h"
#include "ResourceManager.h"
#include "Game.h"
#include "Mesh.h"

SceneManager::SceneManager(shared_ptr<Graphics> graphics)
	: _graphics(graphics)
{
}

void SceneManager::Init()
{
	if (_activeScene == nullptr)
		return;

	_activeScene->Awake();
	_activeScene->Start();
}

void SceneManager::Update()
{
	if (_activeScene == nullptr)
		return;

	_activeScene->Update();
	_activeScene->LateUpdate();
	_activeScene->FixedUpdate();
}

void SceneManager::LoadScene(wstring sceneName)
{
	_activeScene = LoadTestScene();
	Init();
}

shared_ptr<Scene> SceneManager::LoadTestScene()
{
	shared_ptr<Scene> scene = make_shared<Scene>();
	if (_graphics == nullptr)
	{
		int a = 0;
	}
	shared_ptr<GameObject> _monster = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	{
		_monster->GetOrAddTransform();
		auto meshRenderer = make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext());
		_monster->AddComponent(meshRenderer);
		
		auto material = RESOURCES->Get<Material>(L"Default");
		meshRenderer->SetMaterial(material);
		auto mesh = RESOURCES->Get<Mesh>(L"Rectangle");
		meshRenderer->SetMesh(mesh);
		scene->AddGameObject(_monster);
	}

	shared_ptr<GameObject> _camera = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	{
		_camera->GetOrAddTransform();
		_camera->AddComponent(make_shared<Camera>());
		scene->AddGameObject(_camera);
	}
	return scene;
}
