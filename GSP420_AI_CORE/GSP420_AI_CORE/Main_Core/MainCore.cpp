#include "MainCore.h"

MainCore::MainCore(void)
{
}

MainCore::~MainCore(void)
{
}

void MainCore::Startup(void)
{
	this->messageManager = new MessageManager();
	this->entityManager = new EntityManager();
	this->clock = new Clock();

	// init cores
	this->PhysicsManager = new PhysicsInterface;
	this->PhysicsManager->Startup((float*)1000);

	this->AudioCoreSound = GetAudioCoreSound();
	this->AudioCoreSound->Starup();
}

void MainCore::Update(void)
{
	this->clock->UpdateElapsed();
	this->clock->UpdateFPS();

	this->entityManager->Update();
	this->messageManager->Update();

	this->clock->StartUpdate();
	// update cores
	this->PhysicsManager->Update((float*)this->clock->GetElapsed());
	this->clock->EndUpdate();

	this->clock->StartRender();
	// update gfx core
	this->clock->EndRender();

	this->PhysicsManager->Update(this->clock->GetElapsed());

	this->AudioCoreSound->Update();
}


void MainCore::Shutdown(void)
{
	delete messageManager;
	delete entityManager;
	delete clock;

	// shutdown cores
	this->PhysicsManager->Shutdown(new void*);

	this->AudioCoreSound->Shutdown();
}