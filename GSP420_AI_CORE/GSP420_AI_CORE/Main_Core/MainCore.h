#pragma once
#include "Main_Core/ICore.h"
#include "Main_Core/MessageManager.h"
#include "Main_Core/EntityManager.h"
#include "Main_Core/Clock.h"
#include "AIInterface.h"
#include "AudioCore.h"
#include "ScriptingCore.h"



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