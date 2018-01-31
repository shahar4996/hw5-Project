#ifndef _CONVERSATION_H_
#define _CONVERSATION_H_

#include <iostream>
#include "ObjectInterface.h"
#include <set>
#include <list>
#include <chrono>
#include <map>
#include <string>

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
    
    Conversation();
    
    
    //* function name   :   Conversation
    //* Description     :   Constuct new Conversation obj.
    //* Parameters      :   memebers of the conv, list of messages, map of users
    //*                     and if they read the conv. and the update time .
    //* Return value    :   none.
    //**************************************************************************************************
    Conversation(const vector<string> members);
    
    
    Conversation(Conversation& conv);
    
    
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
    
    //**************************************************************************************************
    //* function name   :   Help
    //* Description     :   the function print all the possible commands.
    //* Parameters      :   none.
    //* Return value    :   none.
    //**************************************************************************************************
    void Help() const;
    
    //**************************************************************************************************
    //* function name   :   DisplayParticipants
    //* Description     :   The function print all the participant in the Conversation.
    //* Parameters      :   none.
    //* Return value    :   none.
    //**************************************************************************************************
    void DisplayParticipants();
    
    //**************************************************************************************************
    //* function name   :   DisplayMessages
    //* Description     :   The function print all the messages in the Conversation.
    //* Parameters      :   none.
    //* Return value    :   none.
    //**************************************************************************************************
    void DisplayMessages();
    
    //**************************************************************************************************
    //* function name   :   findUserByName
    //* Description     :   the function search for user in the conversation by name.
    //* Parameters      :   name- the name of the wanted user.
    //* Return value    :   the function return the user if found and NULL else.
    //**************************************************************************************************
    bool UserExist(string name);
    
    //**************************************************************************************************
    //* function name   :   getStatusByName
    //* Description     :   the function check the conv. status of the
    //* Parameters      :   name- the name of the wanted user.
    //* Return value    :   the function return the user if found and NULL else.
    //**************************************************************************************************
    bool IsRead(string name);
    
    void removeUser(string name);
    bool operator<(const Conversation& rhs);
 // ------------------------------- Properties ------------------------------------ //
private:
    set<string> members_;
    list<Message> messages_;
    map<string, ConversationStatus> readList_;
    SysTime updateTime_;
};

#endif
