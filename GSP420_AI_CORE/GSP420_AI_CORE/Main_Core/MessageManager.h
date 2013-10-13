#pragma once
#include "Message.h"

// handles sending messages to intended recipients
class MessageManager
{
private:
	Message *msgFirst;

public:
	MessageManager(void);
	~MessageManager(void);

	// sends all of the messages accumulated this frame
	void Update(void);
	// adds a message to the message queue
	void Add(Message *message);
};