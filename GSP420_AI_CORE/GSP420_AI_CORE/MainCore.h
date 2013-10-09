#pragma once
#include "ICore.h"
#include "MessageManager.h"
#include "EntityManager.h"
#include "Clock.h"
#include"AIInterface.h"


class MainCore : public ICore
{
private:
	MessageManager *messageManager;
	EntityManager *entityManager;
	Clock *clock;
	AIInterface*	AIManager;
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
};