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
#include "CoreManager.h"




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
	CoreManager*		GraphicsManager;


public:

	MainCore(void);
	~MainCore(void);

	void Startup(HWND hWnd, int width, int height, bool windowed);
	void Update();
	void Shutdown();

	MessageManager* GetMessageManager() { return this->messageManager; }
	EntityManager* GetEntityManager() { return this->entityManager; }
	Clock* GetClock() { return this->clock; }
	AISystem*	GetAIManager() {return this->AIManager;}
	Sound* GetAudioCoreSound() {return this->AudioCoreSound; }
	SoundEffect* GetAudioCoreSoundEffect() {return this->AudioCoreSoundEffect; }
	PhysicsInterface* GetPhysicsManager() {return this->PhysicsManager;}
	Input* GetInputManager() {return this->InputManager;}
	UI* GetUIManager() {return this->UIManager;}
	ScriptingCore* GetScriptManager() {return this->ScriptManager;}
	CoreManager* GetGraphicsManager() {return this->GraphicsManager;}

};