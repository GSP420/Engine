#include "MainCore.h"

MainCore::MainCore(void)
{
}

MainCore::~MainCore(void)
{
}

void MainCore::Startup(void* ignore)
{
	this->messageManager = new MessageManager();
	this->entityManager = new EntityManager();
	this->clock = new Clock();

	// init cores
	//this->PhysicsManager = new PhysicsInterface;
	//this->PhysicsManager->Startup((float*)1000);

}

void MainCore::Update(void* ignore)
{
	this->clock->UpdateElapsed();
	this->clock->UpdateFPS();

	this->entityManager->Update();
	this->messageManager->Update();

	this->clock->StartUpdate();
	// update cores
	float dt = this->clock->GetElapsed();
	//this->PhysicsManager->Update(&dt);

	this->clock->EndUpdate();

	this->clock->StartRender();
	// update gfx core
	this->clock->EndRender();

	//this->UIManager->Update(// GAMESTATE (ENUM or INT);
}


void MainCore::Shutdown(void* ignore)
{
	delete messageManager;
	delete entityManager;
	delete clock;

	// shutdown cores
	//this->PhysicsManager->Shutdown(new void*);

}