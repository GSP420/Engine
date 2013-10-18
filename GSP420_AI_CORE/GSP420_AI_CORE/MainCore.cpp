#include "MainCore.h"

MainCore::MainCore(void)
{
}

MainCore::~MainCore(void)
{
}

void MainCore::Startup(HWND hWnd, int width, int height, bool windowed)
{
	this->messageManager = new MessageManager();
	this->entityManager = new EntityManager();
	this->clock = new Clock();

	// init cores
	this->AIManager = new AISystem();

	this->PhysicsManager = new PhysicsInterface;
	this->PhysicsManager->Startup(1000);

	this->AudioCoreSound = GetAudioCoreSound();
	this->AudioCoreSound->Startup();

	this->InputManager = GetInputManager();
	this->InputManager->Startup();

	this->ScriptManager = GetScriptManager();
	this->ScriptManager->Startup();

	this->GraphicsManager->DXInit(hWnd, width, height, windowed);
	

}

void MainCore::Update()
{
	this->clock->UpdateElapsed();
	this->clock->UpdateFPS();

	this->entityManager->Update();
	this->messageManager->Update();

	this->clock->StartUpdate();
	// update cores
	
	float dt = this->clock->GetElapsed();
	this->PhysicsManager->Update(dt);
	//this->AIManager->AI_Update();
	this->ScriptManager->Update();
	
	this->clock->EndUpdate();

	this->clock->EndUpdate();

	this->clock->StartRender();
	// update gfx core
	this->GraphicsManager->Update();
	this->clock->EndRender();

	
}


void MainCore::Shutdown()
{
	delete messageManager;
	delete entityManager;
	delete clock;

	// shutdown cores
	this->PhysicsManager->Shutdown();

}

	MessageManager* MainCore::GetMessageManager() { return this->messageManager; }
	EntityManager* MainCore::GetEntityManager() { return this->entityManager; }
	Clock* MainCore::GetClock() { return this->clock; }
	AISystem*	MainCore::GetAIManager() {return this->AIManager;}
	Sound* MainCore::GetAudioCoreSound() {return this->AudioCoreSound; }
	SoundEffect* MainCore::GetAudioCoreSoundEffect() {return this->AudioCoreSoundEffect; }
	PhysicsInterface* MainCore::GetPhysicsManager() {return this->PhysicsManager;}
	Input* MainCore::GetInputManager() {return this->InputManager;}
	UI* MainCore::GetUIManager() {return this->UIManager;}
	ScriptingCore* MainCore::GetScriptManager() {return this->ScriptManager;}
	CoreManager* MainCore::GetGraphicsManager() {return this->GraphicsManager;}