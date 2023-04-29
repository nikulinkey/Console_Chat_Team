#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Message.h"

class Chat
{
	std::vector<Message> messages_;
	bool chatWorks_ = false;

	void chatMenu();
	void sendMessage();
	void showMessages();
	std::vector<Message>& getMessages() { return messages_; }
public:
	void chatStart();
	bool chatWorks() { return chatWorks_; }
	void chatShutdown() { chatWorks_ = false; }
};