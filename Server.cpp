#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <exception>
#include "User.h"
#include "Server.h"
#include "Message.h"


void Server::signIn()
{
	std::string id, password;
	std::cout << "User ID: " << std::endl;
	std::cin >> id;
	std::cout << "password" << std::endl;
	std::cin >> password;

	currentUser_ = getUserByID(id);
	if (currentUser_ == nullptr)
	{
		currentUser_ = nullptr;
		throw UserNameExcpt();
	}
	else if (password != currentUser_->getUserPassword())
	{
		std::cout << "Wrong password" << std::endl;
		currentUser_ = nullptr;
	}
	else
		std::cout << "Successful authorization. Welcome " << currentUser_ -> getUserName() << "!" << std::endl;
}
void Server::signUp()
{
	std::string id, password, name;
	std::cout << "Enter your user ID: " << std::endl;
	std::cin >> id;
	std::cout << "Enter your Name" << std::endl;
	std::cin >> name;
	std::cout << "Enter your Password" << std::endl;
	std::cin >> password;

	if (getUserByID(id) != nullptr || id == "all") 
	{
		throw UserIdExcpt();
	}

	User newUser = User(id, name, password);
	users_.push_back(newUser);
	currentUser_ = getUserByID(id);
	std::cout << "Registration complete! Welcome " << currentUser_ -> getUserName() << "!" << std::endl;
}
void Server::sendMessage()
{
	std::string to, message;
	std::cout << "enter user name or 'all'" << std::endl;
	std::cin >> to;
	for (auto& u : users_)
	{
		if (getUserByName(to) == nullptr && to != "all")
		{
			throw UserNameExcpt();
		}
	}
	std::cout << "Enter message:" << std::endl;
    std::cin.ignore();
	std::getline(std::cin, message);
	Message newMessage = Message(currentUser_->getUserName(), to, message);
	messages_.push_back(newMessage);
}
void Server::showMessages()
{
	std::cout << "______Chat:______" << std::endl;
	for (auto& mess : messages_)
	{
		if (mess.getFrom() == currentUser_->getUserName() || mess.getTo() == currentUser_->getUserName() || mess.getTo() == "all")
		{
			std::cout << "@" << mess.getFrom() << " - to " << mess.getTo() << " : " << mess.getMessage() << std::endl;
		}
	}
	std::cout << "_______End_______" << std::endl;
}

std::shared_ptr<User> Server::getUserByID(const std::string& id) const
{
	for (auto& user : users_)
	{
		if (id == user.getUserId())
			return std::make_shared<User>(user);
	}
	return nullptr;
}
std::shared_ptr<User> Server::getUserByName(const std::string& name) const
{
	for (auto& user : users_)
	{
		if (name == user.getUserName())
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
		
			serverMenu();
			char choise;
			std::cin >> choise;
			switch (choise)
			{
			case '1':
				showAllUsers();
				break;
			case '2':
				try
				{
					signIn();
				}
				catch (const std::exception& except)
				{
					std::cout << except.what() << std::endl;
				}
				break;
			case '3':
				try 
				{
					signUp();
				}
				catch (const std::exception& except)
				{
					std::cout << except.what() << std::endl;
				}
				break;
			case '4':
				currentUser_ = nullptr;
				serverShutdown();
				break;
			default:
				std::cout << "Wrong choice, try again!" << std::endl;
				break;
			}	
		
		if(currentUser_ != nullptr)
			chatMenu();
	} while (serverWorks());
}
void Server::serverMenu()
{
	std::cout << "|Login or Register       |" << std::endl;
	std::cout << "|print 1 for (Show Users)|" << std::endl;
	std::cout << "|print 2 for (Sign_In)   |" << std::endl;
	std::cout << "|print 3 for (Sign_Up)   |" << std::endl;
	std::cout << "|print 4 for (Quit)      |" << std::endl;
	std::cout << "|________________________|" << std::endl;
}

void Server::chatMenu()
{
	chatWorks_ = true;
	do {
		std::cout << "|1 - Send message|" << std::endl;
		std::cout << "|2 - Show chat   |" << std::endl;
		std::cout << "|3 - Log out     |" << std::endl;
		std::cout << "|________________|" << std::endl;

		char choise;
		std::cin >> choise;

		switch (choise)
		{
		case '1':
			try
			{
				sendMessage();
			}
			catch (const std::exception& except)
			{
				std::cout << except.what() << std::endl;
			}
			break;
		case '2':
			showMessages();
			break;
		case '3':
			chatShutdown();
			break;
		default:
			std::cout << "Wrong choice, try again!" << std::endl;
			break;
		}
	} while (chatWorks());
}
void Server::showAllUsers()
{
	for (auto& user : users_)
		std::cout << user.getUserName() << std::endl;
}




