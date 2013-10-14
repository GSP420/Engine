#pragma once
#include "ICore.h"
#include "MessageManager.h"
#include "EntityManager.h"
#include "Clock.h"
#include "AIInterface.h"
#include "AudioCore.h"
#include "ScriptingCore.h"
#include "PhysicsInterface.h"
#include "Input.h"
#include "UI.h"
#include "DXManager.h"


class MainCore : public ICore
{
private:
	MessageManager *messageManager;
	EntityManager *entityManager;
	Clock *clock;
	AIInterface*	AIManager;
	Sound* AudioCoreSound;
	SoundEffect* AudioCoreSoundEffect;
	PhysicsInterface* PhysicsManager;
	Input* InputManager;
	UI*    UIManager;
	ScriptingCore* ScriptManager;
	DXManager*		GraphicsManager;

public:

	MainCore(void);
	~MainCore(void);

	void Startup(void);
	void Update(void);
	void Shutdown(void);

	MessageManager* GetMessageManager() { return this->messageManager; }
	EntityManager* GetEntityManager() { return this->entityManager; }
	Clock* GetClock() { return this->clock; }
	AIInterface*	GetAIManager() {return this->AIManager;}
	Sound* GetAudioCoreSound() {return this->AudioCoreSound; }
	SoundEffect* GetAudioCoreSoundEffect() {return this->AudioCoreSoundEffect; }
	PhysicsInterface* GetPhysicsManager() {return this->PhysicsManager;}
	Input* GetInputManager() {return this->InputManager;}
	UI* GetUIManager() {return this->UIManager;}
	ScriptingCore* GetScriptManager() {return this->ScriptManager;}
	DXManager* GetGraphicsManager() {return this->GraphicsManager;}
};