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
}

void MainCore::Update(void)
{
	this->clock->UpdateElapsed();
	this->clock->UpdateFPS();

	this->entityManager->Update();
	this->messageManager->Update();

	this->clock->StartUpdate();
	// update cores
	this->clock->EndUpdate();

	this->clock->StartRender();
	// update gfx core
	this->clock->EndRender();
}


void MainCore::Shutdown(void)
{
	delete messageManager;
	delete entityManager;
	delete clock;

	// shutdown cores
}