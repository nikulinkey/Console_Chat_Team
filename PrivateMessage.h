#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Server.h"
#include "User.h"
#include "Message.h"

// Неудачная попытка добавления фичи

//class PM
//{
//	bool pmWorks_ = false;
//	std::string userName_, partnerName_, roomName_;
//	std::vector<Message> pmessages_;
//
//	std::vector<Message>& getPMessages() { return pmessages_; }
//	void pmStartWorks() { pmWorks_ = true; }
//	void pmShutdown() { pmWorks_ = false; }
//	bool pmWorks() { return pmWorks_; }
//
//public:
//	std::string getRoomName() const { return roomName_; }
//
//	PM(const std::string &uname, const std::string &pname, const std::string &rname) : userName_(uname), partnerName_(pname), roomName_(rname) {}
//	void sendMessage(std::vector<Message>& pmessages_);
//	void showMessages(const std::vector<Message>& pmessages_);
//	
//	void PMMenu();
//	void pmStart();
//	
//	
//};