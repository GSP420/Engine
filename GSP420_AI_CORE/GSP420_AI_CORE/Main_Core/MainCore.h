#pragma once
#include "ICore.h"
#include "MessageManager.h"
#include "EntityManager.h"
#include "Clock.h"
#include "../AI_Core/AIInterface.h"
#include "../Audio_Core/AudioCore.h"
#include "../Scripting_Core/ScriptingCore.h"
#include "../Physics_Core/PhysicsInterface.h"
#include "../UI_Core/Input.h"
#include "../UI_Core/UI.h"


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
};