#pragma once
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
	bool chatWorks()  const { return chatWorks_; }
	void chatShutdown() const { chatWorks_ = false; }
};
