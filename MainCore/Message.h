#pragma once
#include <string>
#include "IDispatcher.h"

// this is essentially a data class that holds message data
class Message
{
private:
public:
	Message(std::string contents, IDispatcher *sender, IDispatcher *recipient);
	~Message(void);

	// the contents of the message
	std::string contents;
	// the sender of the message
	IDispatcher *sender;
	// the intended recipient of the message
	IDispatcher *recipient;

	// points to the next message (for MessageManager)
	Message *msgNext;
};