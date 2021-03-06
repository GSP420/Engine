#pragma once
#include "MessageManager.h"
#include "EntityManager.h"
#include "Clock.h"
#include "AISystem.h"
#include "AudioCore.h"
#include "ScriptingCore.h"
#include "PhysicsInterface.h"
#include "Input.h"
#include "UI.h"





class MainCore
{
private:
	MessageManager *messageManager;
	EntityManager *entityManager;
	Clock *clock;
	AISystem*	AIManager;
	Sound* AudioCoreSound;
	SoundEffect* AudioCoreSoundEffect;
	PhysicsInterface* PhysicsManager;
	Input* InputManager;
	UI*    UIManager;
	ScriptingCore* ScriptManager;



public:

	MainCore(void);
	~MainCore(void);

	void Startup(HWND hWnd);
	void Update(Entity* enemy, int gameState);
	void Shutdown();
	MessageManager* GetMessageManager();
	EntityManager* GetEntityManager();
	Clock* GetClock();
	AISystem*	GetAIManager();
	Sound* GetAudioCoreSound();
	SoundEffect* GetAudioCoreSoundEffect();
	PhysicsInterface* GetPhysicsManager();
	Input* GetInputManager();
	UI* GetUIManager();
	ScriptingCore* GetScriptManager();

};