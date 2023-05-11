#pragma once
#include <string>
#include <fstream>
#include <ostream>
#include <istream>



class Message
{
	 std::string from_;
	 std::string to_;
	 std::string message_;

public:
	Message(const std::string& from, const std::string& to, const std::string& message) :
		from_(from), to_(to), message_(message) {}
	Message() = default;
	Message(const Message& mess)
	{
		from_ = mess.from_;
		to_ = mess.to_;
		message_ = mess.message_;
	}
	Message& operator=(const Message& mess)
	{
		from_ = mess.from_;
		to_ = mess.to_;
		message_ = mess.message_;
	}
	friend std::ostream& operator<<(std::ostream& os, const Message& mess)
	{
		os << mess.from_ << mess.to_ << mess.message_;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Message& mess) 
	{
		is >> mess.from_ >> mess.to_ >> mess.message_ ;
		return is;
	}
	

	std::string getFrom() const { return from_; }
	std::string getTo() const { return to_; }
	std::string getMessage() const { return message_; }
};
