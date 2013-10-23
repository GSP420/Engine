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
	this->clock->StartUpdate();
	// init cores
	this->AIManager = new AISystem();

	this->PhysicsManager = new PhysicsInterface;
	this->PhysicsManager->Startup(1000);

	this->AudioCoreSound = new Sound();
	this->AudioCoreSound->Startup();

	this->InputManager = new Input();
	this->InputManager->Startup(hWnd);

	//this->ScriptManager = new ScriptingCore();
	//this->ScriptManager->Startup();

	this->GraphicsManager = new CoreManager();
	this->GraphicsManager->DXInit(hWnd, width, height, windowed);
	

}

void MainCore::Update(Entity* enemy, int gameState)
{
	D3DXVECTOR3 temp;
	D3DXVECTOR3 temp2, temp3;
	this->clock->UpdateElapsed();
	this->clock->UpdateFPS();

	this->entityManager->Update();
	this->messageManager->Update();

	
	// update cores
	
	float dt = this->clock->GetElapsed();
	if(gameState == 2)
	{
		this->AIManager->AI_Update();
		/*
		//from AI update and use physics for further calculations
		enemy->agentData.getPosition(temp);
		enemy->agentData.getAcceleration(temp2);
		enemy->agentData.getDestination(temp3);
		temp2 += temp3; //check this for correctness
		this->PhysicsManager->setAccel(temp2, "enemy");
		temp2 = this->PhysicsManager->getVel("enemy");
		enemy->agentData.setAcceleration(temp2);
		enemy->agentData.setPosition(temp + temp2);
		//this->PhysicsManager->Update(dt);
		*/
	}
	this->InputManager->Update();
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