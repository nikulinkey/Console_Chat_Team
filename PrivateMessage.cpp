#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include "Server.h"
#include "User.h"
#include "Message.h"
#include "PrivateMessage.h"

//Неудачная попытка добавления фичи.

void PM::pmMenu()
{
	std::cout << "1 - send message" << std::endl;
	std::cout << "2 - show messages" << std::endl;
	std::cout << "3 - quit to server menu" << std::endl;
}
void PM::pmStart()
{
	pmWorks_ = true;
	
	std::cout << "You are chating with" << partnerName_ << std::endl;
	do {
		pmMenu();
		char choise;
		std::cout << "your choise: " << std::endl;
		std::cin >> choise;
		switch (choise)
		{
		case '1':
			sendMessage(pmessages_);
			break;
		case '2':
			showMessages(pmessages_);
			break;
		case '3':
			pmShutdown();
			break;
		default:
			std::cout << "Wrong coise, try again!" << std::endl;
		}
	} while (pmWorks());
	
}

void PM::sendMessage(std::vector<Message>& pmessages_)
{
	std::cout << "Choose sender:" << std::endl;
	std::cout << "1 - " << userName_ << std::endl;
	std::cout << "2 - " << partnerName_ << std::endl;
	char choise;
	std::cin >> choise;
	std::string from;
	std::string to;
	switch (choise)
	{
	case '1':
		from = userName_;
		to = partnerName_;
		break;
	case '2':
		from = partnerName_;
		to = userName_;
		break;
	default:
		std::cout << "Wrong coise, try again!" << std::endl;
		break;
	}
	std::cout << "text:" << std::endl;
	std::string message;
	std::cin.ignore();
	std::getline(std::cin, message);
	Message newMessage = Message(from, to, message);
	pmessages_.emplace_back(newMessage);
	std::fstream ofs("file.txt");
	std::copy(pmessages_.begin(), pmessages_.end(), std::ostream_iterator<Message>(ofs));
}

void PM::showMessages(std::vector<Message>& pmessages_)
{
	std::fstream ifs("file.txt");
	std::copy(std::istream_iterator<Message>(ifs), std::istream_iterator<Message>(), std::back_inserter(pmessages_));

	for (auto& mess : pmessages_)
	{
		//if(mess.getFrom() == userName_ || mess.getFrom() == partnerName_)
		std::cout << mess.getFrom() << " : " << mess.getMessage() << std::endl;
	}
}

