#pragma once
#include "ICore.h"
#include "MessageManager.h"
#include "EntityManager.h"
#include "Clock.h"
#include "../AI_Core/AIInterface.h"
#include "../Audio_Core/AudioCore.h"
#include "../Scripting_Core/ScriptingCore.h"



class MainCore : public ICore
{
private:
	MessageManager *messageManager;
	EntityManager *entityManager;
	Clock *clock;
	AIInterface*	AIManager;
	Sound* AudioCoreSound;
	SoundEffect* AudioCoreSoundEffect;
	

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
};