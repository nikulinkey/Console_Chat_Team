#pragma once
#include <string>
#include <iostream>

class Message
{
	const std::string from_;
	const std::string to_;
	const std::string message_;

public:
	Message (const std::string& from, const std::string& to, const std::string& message) :
		from_(from), to_(to), message_(message) {}

	std::string getFrom() const { return from_; }
	std::string getTo() const { return to_; }
	std::string getMessage() const { return message_; }
};