#ifndef _CONVERSATION_H_
#define _CONVERSATION_H_

#include "ObjectInterface.h"
#include <set>
#include <list>
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
class Conversation : public ObjectInterface {
// ------------------------------- Methods ------------------------------------ //
public:
    //**************************************************************************************************
    //* function name   :   Conversation
    //* Description     :   Constuct new Conversation obj.
    //* Parameters      :   memebers of the conv, list of messages, map of users
    //*                     and if they read the conv. and the update time .
    //* Return value    :   none.
    //**************************************************************************************************
    Conversation(set<User> members, list<Message> messages, map<ConversationStatus, User> readList, SysTime updateTime) : members_(members), messages_(messages), readList_(readList), updateTime_(updateTime) {}
    //**************************************************************************************************
    //* function name   :   Preview
    //* Description     :   if the user is part of the conversation we will print it on the screen.
    //* Parameters      :   the name of the active user.
    //* Return value    :   none.
    //**************************************************************************************************
    void Preview(string activeUsrName);
    //**************************************************************************************************
    //* function name   :   VrtDo
    //* Description     :   the function get the command and execute it. there are two commands: Write and Back.
    //* Parameters      :   cmd- the command
    //*                     activeUsrName - the name of the user
    //* Return value    :   none.
    //**************************************************************************************************
    void VrtDo(string cmd, string activeUsrName);
    
 // ------------------------------- Properties ------------------------------------ //
private:
    set<User> members_;
    list<Message> messages_;
    map<ConversationStatus, User> readList_;
    SysTime updateTime_;
};


#endif
