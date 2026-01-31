#include "pch.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Camera.h"
#include "GameObject.h"
#include "Transform.h"
#include "MeshRenderer.h"

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
	shared_ptr<GameObject> _gameObject = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	{
		_gameObject->GetOrAddTransform();
		_gameObject->AddComponent(make_shared<MeshRenderer>(_graphics->GetDevice(), _graphics->GetDeviceContext()));
		_gameObject->GetTransform()->SetScale(Vec3(100.f, 100.f, 1.f));
		scene->AddGameObject(_gameObject);
	}

	shared_ptr<GameObject> _camera = make_shared<GameObject>(_graphics->GetDevice(), _graphics->GetDeviceContext());
	{
		_camera->GetOrAddTransform();
		_camera->AddComponent(make_shared<Camera>());
		scene->AddGameObject(_camera);
	}
	return scene;
}
