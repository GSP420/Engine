#include "MessageManager.h"

MessageManager::MessageManager(void)
{
	msgFirst = nullptr;
}

MessageManager::~MessageManager(void)
{
}

void MessageManager::Update(void)
{
	// loop through messages
		// send them to the proper entity
		// remove from list
	Message *m = msgFirst;
	while(m)
	{
		m->recipient->Recieve(m);
		m = m->msgNext;
	}
}

void MessageManager::Add(Message *message)
{
	// set message->msgNext to msgFirst
	message->msgNext = msgFirst;
	// set msgFirst to message
	msgFirst = message;
}
