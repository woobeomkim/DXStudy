#pragma once

#include "GameObject.h"
#include "Pipeline.h"

class SceneManager;
class InputManager;
class ResourceManager;
class TimeManager;

class Game
{
public :
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

	shared_ptr<SceneManager> GetSceneManager() { return _scene; }
	shared_ptr<InputManager> GetInputManager() { return _input; }
	shared_ptr<ResourceManager> GetResourceManager() { return _resource; }
	shared_ptr<TimeManager> GetTimeManager() { return _time; }

	shared_ptr<Pipeline> GetPipeline() { return _pipeline; }
private:
	HWND _hwnd = nullptr;

	shared_ptr<Graphics> _graphics;
	shared_ptr<Pipeline> _pipeline;

private:
	shared_ptr<SceneManager> _scene;
	shared_ptr<InputManager> _input;
	shared_ptr<ResourceManager> _resource;
	shared_ptr<TimeManager> _time;

};

extern unique_ptr<Game> GGame;