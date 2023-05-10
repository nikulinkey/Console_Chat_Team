#pragma once
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include "User.h"
#include "Message.h"

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
	std::vector<User>users_;
	std::vector<Message> messages_;

	std::shared_ptr<User> currentUser_{ nullptr };
	
	void signIn();
	void signUp();

	void sendMessage();
	void showMessages();

	void serverShutdown() { serverWorks_ = false; };
	void chatShutdown() { chatWorks_ = false; }
	bool serverWorks() const { return serverWorks_; }
	bool chatWorks() const { return chatWorks_; }

	std::shared_ptr<User> getUserByID(const std::string& id) const;
	std::shared_ptr<User> getUserByName(const std::string& name) const;
	std::shared_ptr<User> getCurrentUser(const std::string& id) const { return currentUser_; };
	std::vector<Message>& getMessages() { return messages_; }

public:
	

	void serverStart();
	void serverMenu();
	void chatMenu();
	void showAllUsers();
};