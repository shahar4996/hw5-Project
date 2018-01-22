#include <iostream>
#include <exception>
#include "Defs.h"
#include "Conversation.h"
















//Interface
Conversation::Conversation(set<User> members) {
    members_ = members;
    messages_ = *new list<Message>;
    updateTime_ = (SysTime)chrono::system_clock::now();
    readList_ = *new map<string,ConversationStatus>;
    set<User> :: iterator temp = members.begin();
    for (int i = 0; i<(int)members.size(); i++) {
        readList_[temp->getUserName()] = READ;
        temp++;
    }
}

bool Conversation::UserExist(string name) {
    set<User> :: iterator temp = members_.begin();
    for (int i = 0; i<(int)members_.size(); i++) {
        if(temp->getUserName() == name)
            return true;
        temp++;
    }
    return false;
}

ConversationStatus Conversation::getStatusByName(string name) {
    return readList_[name];
}


void Conversation::VrtDo(string cmdLine, string activeUsrName)
{
	vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES, 1);
	if (cmdLineTokens[0] == "Write" && cmdLineTokens.size() == 2) // Write
	{
        if (UserExist(activeUsrName)) {
            Message newMes = Message(activeUsrName, cmdLineTokens[2]);
            messages_.push_back(newMes);
            updateTime_ = chrono::system_clock::now();
            set<User> :: iterator temp = members_.begin();
            for (int i = 0; i < (int)members_.size(); i++) {
                readList_[temp->getUserName()] = UNREAD;
                temp++;
            }
            readList_[activeUsrName] = READ;
        }
		else
            cout << activeUsrName << NOT_IN_THE_CONVERSATION << endl;
	}
    
	else if (cmdLineTokens[0] == "Back" && cmdLineTokens.size() == 1) // Back
	{
		// add code here
	}
	else // INVALID_INPUT
		cout << INVALID_INPUT;
}


//**************************************************************************************************
//* function name   :   Preview
//* Description     :   if the user is part of the conversation we will print it on the screen.
//* Parameters      :   the name of the active user.
//* Return value    :   none.
//**************************************************************************************************
void Conversation::Preview(string activeUsrName)
{
    set<User> :: iterator temp = members_.begin();
    for (int i = 0; i< (int)members_.size(); i++) {
        if(temp->getUserName() == activeUsrName)
        {
            readList_[activeUsrName] = READ;
            cout << PARTICIPANTS_TITLE << endl;
            DisplayParticipants();
            DisplayMessages();
            return;
            // print and exit func
        }
        temp++;
    }
    cout << NOT_IN_THE_CONVERSATION << endl;
}

//**************************************************************************************************
//* function name   :   DisplayParticipants
//* Description     :   The function print all the participant in the Conversation.
//* Parameters      :   none.
//* Return value    :   none.
//**************************************************************************************************
void Conversation::DisplayParticipants() {
    cout <<
}

void Conversation::Help() const
{
	cout << "Write <message>" << endl;
	cout << "Back" << endl;
}
