#pragma once
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include "User.h"
#include "Message.h"
#include "PrivateMessage.h"

struct UserIdExcpt : public std::exception
{
	const char* what() const noexcept override { return "Wrong User ID: this ID already exists"; }
};
struct UserNameExcpt : public std::exception
{
	const char* what() const noexcept override { return "User does not exist"; }
};

class Server
{
	bool serverWorks_ = false;
	bool chatWorks_ = false;
	bool pchatWorks_ = false;
	std::vector<User>users_;
	std::shared_ptr<User> currentUser_{ nullptr };

	std::vector<Message> messages_;
	
	std::vector<PM> pchats_;
	std::shared_ptr<PM> currentPchat_{ nullptr };
	
	void signIn();
	void signUp();

	void sendMessage();
	void showMessages();

	void serverShutdown() { serverWorks_ = false; };
	void chatShutdown() { chatWorks_ = false; }
	void pchatShutdown() { pchatWorks_ = false; }

	bool serverWorks() const { return serverWorks_; }
	bool chatWorks() const { return chatWorks_; }
	bool pchatWorks() const { return pchatWorks_; }



	std::shared_ptr<User> getUserByID(const std::string& id) const;
	std::shared_ptr<User> getUserByName(const std::string& name) const;
	std::shared_ptr<User> getCurrentUser(const std::string& id) const { return currentUser_; };
	std::vector<Message>& getMessages() { return messages_; }

	std::shared_ptr<PM> getPchatByRoom(const std::string& name) const;
	
public:
	
	void pmMenu();
	void serverStart();
	void serverMenu();
	void chatMenu();
	void showAllUsers();
};