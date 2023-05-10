#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include "Server.h"
#include "User.h"
#include "Message.h"
#include "PrivateMessage.h"

//Неудачная попытка добавления фичи.

//void PM::PMMenu()
//{
//	std::cout << "1 - send message" << std::endl;
//	std::cout << "2 - show messages" << std::endl;
//	std::cout << "3 - quit to server menu" << std::endl;
//}
//void PM::pmStart()
//{
//	pmWorks_ = true;
//
//	std::cout << "You are chating with" << partnerName_ << std::endl;
//	do {
//		PMMenu();
//		char choise;
//		std::cout << "your choise: " << std::endl;
//		std::cin >> choise;
//		switch (choise)
//		{
//		case '1':
//			sendMessage(pmessages_);
//			break;
//		case '2':
//			showMessages(pmessages_);
//			break;
//		case '3':
//			pmShutdown();
//			break;
//		default:
//			std::cout << "Wrong coise, try again!" << std::endl;
//		}
//	} while (pmWorks());
//}
//
//void PM::sendMessage(std::vector<Message>& pmessages_)
//{
//	std::cout << "Choose sender:" << std::endl;
//	std::cout << "1 - " << userName_ << std::endl;
//	std::cout << "2 - " << partnerName_ << std::endl;
//	char choise;
//	std::cin >> choise;
//	std::string from;
//	std::string to;
//	switch (choise)
//	{
//	case '1':
//		from = userName_;
//		to = partnerName_;
//		break;
//	case '2':
//		from = partnerName_;
//		to = userName_;
//		break;
//	default:
//		std::cout << "Wrong coise, try again!" << std::endl;
//		break;
//	}
//	std::string message;
//	std::cin.ignore();
//	std::getline(std::cin, message);
//	//std::shared_ptr<Message> newMessage = std::make_shared<Message>(from, to, message);
//	Message newMessage = Message(from, to, message);
//	//Message *newMessage = new Message(from, to, message);
//	pmessages_.emplace_back(newMessage);
//}
//
//void PM::showMessages(const std::vector<Message>& pmessages_)
//{
//	for (auto& mess : pmessages_)
//	{
//		//if(mess.getFrom() == userName_ || mess.getFrom() == partnerName_)
//		std::cout << mess.getFrom() << " : " << mess.getMessage() << std::endl;
//	}
//}

