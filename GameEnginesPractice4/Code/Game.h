#pragma once

#include "RenderEngine.h"
#include "FileSystem/FileSystem.h"
#include "ResourceManager.h"
#include "Input/InputHandler.h"
#include "GameTimer.h"
#include "flecs.h"

class Game
{
public:
	Game();
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void Run();
	bool Update();

private:
	GameTimer m_Timer;
  flecs::world ecs;

	RenderEngine* m_pRenderEngine;
	FileSystem* m_pFileSystem;
	ResourceManager* m_pResourceManager;
	InputHandler* m_pInputHandler;
};

