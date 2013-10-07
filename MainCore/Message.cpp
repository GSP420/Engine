#include "Message.h"

Message::Message(std::string contents, IDispatcher *sender, IDispatcher *recipient)
{
	msgNext = nullptr;

	// set vars to parameters
	this->contents = contents;
	this->sender = sender;
	this->recipient = recipient;
}

Message::~Message(void)
{
}