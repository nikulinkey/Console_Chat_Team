#pragma once
#include <string>
#include <iostream>

class User
{
	const std::string userId_;
	std::string userName_;
	std::string password_;

public:
	User(const std::string& id, const std::string& name, const std::string& password) :
		userId_(id), userName_(name), password_(password) {}

	const std::string& getUserId() const { return userId_; }
	const std::string& getUserName() const { return userName_; }
	const std::string& getUserPassword() const { return password_; }

	void setUserName(const std::string& name) { userName_ = name; }
	void setPassword(const std::string& password) { password_ = password; }

};