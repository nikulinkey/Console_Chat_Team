#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include "User.h"

struct UserIdExcpt : public std::exception
{
	const char* what() const noexcept override { return "Wrong User ID: this ID already exists"; }
};

class Server
{
	bool serverWorks_ = false;
	std::vector<User>users_;
	std::shared_ptr<User> currentUser_{ nullptr };
	void signIn();
	void signUp();
	std::shared_ptr<User> getUserByID(const std::string& id) const;
	std::shared_ptr<User> getUserByName(const std::string& name) const;
	void serverShutdown() { serverWorks_ = false; };

public:
	void serverStart();
	bool serverWorks() const { return serverWorks_; }
	void chatStrat();
	void showAllUsers();
	std::shared_ptr<User> getCurrentUser(const std::string& id) const { return currentUser_; };
	void serverMenu();
	

};