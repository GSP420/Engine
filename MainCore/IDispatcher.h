#pragma once
#include "Message.h"

class Message;

class IDispatcher
{
public:
	virtual void Recieve(Message *message) = 0;
	virtual void Send(Message *message) = 0;
};