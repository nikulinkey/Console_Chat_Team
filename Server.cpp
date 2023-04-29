#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include "User.h"
#include "Server.h"
#include "Chat.h"

void Server::signIn()
{
	std::string id, password;

	std::cout << "User ID: " << std::endl;
	std::cin >> id;
	std::cout << "password" << std::endl;
	std::cin >> password;

	currentUser_ = getSomeUser(id);
	if (currentUser_ == nullptr)
	{
		std::cout << "User does not exist" << std::endl;
		currentUser_ = nullptr;
	}
	else if (password != currentUser_->getUserPassword())
	{
		std::cout << "Wrong password" << std::endl;
		currentUser_ = nullptr;
	}
	else
		std::cout << "Successful authorization. Welcome " << currentUser_ -> getUserName() << std::endl;
}
void Server::signUp()
{
	std::string id, password, name;
	std::cout << "Enter your user ID: " << std::endl;
	std::cin >> id;
	std::cout << "Enter your Name" << std::endl;
	std::cin >> name;
	std::cout << "password" << std::endl;
	std::cin >> password;

	if (getSomeUser(id) != nullptr || id == "all") // Здесь вылазит ошибка доступа к указателю пока не понятно почему
	{
		throw UserIdExcpt();
	}

	User newUser(id, name, password);
	users_.push_back(newUser);
	currentUser_ = getSomeUser(id);
	std::cout << "Registration complete! Welcome " << currentUser_ -> getUserName() << std::endl;
}
std::shared_ptr<User> Server::getSomeUser(const std::string& id) const
{
	for (auto& user : users_)
	{
		if (id == user.getUserId())
			return std::make_shared<User>(user);
	}
	return nullptr;
}
void Server::serverStart()
{
	currentUser_ = nullptr;
	do 
	{
		serverWorks_ = true;
		while (currentUser_ == nullptr)
		{
			serverMenu();
			char choise;
			std::cin >> choise;
			switch (choise)
			{
			case '1':
				showAllUsers();
				break;
			case '2':
				signIn();
				break;
			case '3':
				signUp();
				break;
			case '4':
				serverShutdown();
				break;
			default:
				std::cout << "Wrong choice, try again!" << std::endl;
				break;
			}
			chatStrat();
		}

	} while (serverWorks_);
}
void Server::chatStrat()
{
	Chat chat;
	chat.chatStart();
}
void Server::showAllUsers()
{
	for (auto& user : users_)
		std::cout << user.getUserId() << std::endl;
}
void Server::serverMenu()
{
	std::cout << "Login or Register" << std::endl;
	std::cout << "print 1 for (Show Users)" << std::endl;
	std::cout << "print 2 for (Sign_In)" << std::endl;
	std::cout << "print 3 for (Sign_Up)" << std::endl;
	std::cout << "print 4 for (Quit)" << std::endl;
}