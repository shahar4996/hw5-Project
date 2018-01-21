#ifndef _CONVERSATION_H_
#define _CONVERSATION_H_

#include "ObjectInterface.h"
#include <string>
#include <chrono>
#include "User.h"
#include <map>

enum ConversationStatus { READ, UNREAD };

typedef chrono::system_clock::time_point SysTime;

// ------------------------------- Message ------------------------------- //
class Message {
public:
	Message(const string& by, const string& content) : by_(by), content_(content) {}
	void Print() const { cout << by_ << " : " << content_ << endl; }
private:
	string by_;
	string content_;
};



// ------------------------------- Conversation ------------------------------- //
class Conversation {};

#endif
