#include <iostream>
#include <string>
#include <vector>
#include "Chat.h"
#include "User.h"
#include "Message.h"


void Chat::chatMenu(){
	std::cout << "1.Write message || 2.Show chat || 3. Stop chat" << std::endl;
	std::cout << "______________________________________________" << std::endl;
}
void Chat::sendMessage(){
}
void Chat::showMessages(){}
void Chat::chatStart() {
	do {
		chatWorks_ = true;
		chatMenu();
		char choise{0};
		std::cin >> choise;
		switch (choise)
		{
		case '1':
		    sendMessage();
		    break;
		case '2':
			showMessages();
			break;
		case '3':
			chatShutdown();
			break;
		default:
			std::cout << "Wrong choise, try again!" << std::endl;
			break;
		}
	} while (chatWorks_);
}
