#pragma once
#include <string>
#include <vector>
#include "Server.h"
#include "User.h"
#include "Message.h"

class PM
{
	std::vector<Message> pmessages_;
	bool pmWorks_ = false;

	void PMMenu();
	void sendMessage();
	void showMessages();
	void showPartnerMessage();
	std::vector<Message>& getMessages() { return pmessages_; }
public:
	void pmStart();
	bool pmWorks() { return pmWorks_; }
	void pmShutdown() { pmWorks_ = false; }
};