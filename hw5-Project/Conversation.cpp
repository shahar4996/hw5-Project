#include <iostream>
#include <exception>
#include "Defs.h"
#include "Conversation.h"



//Interface
Conversation::Conversation(vector<string> members) {
    for (int i = 0; i < (int)members.size(); i++) {
        members_.insert(members.at(i));
    }
    messages_ = *new list<Message>;
    updateTime_ = (SysTime)chrono::system_clock::now();
    readList_ = *new map<string,ConversationStatus>;
    set<string> :: iterator temp = members_.begin();
    for (int i = 0; i<(int)members.size(); i++) {
        readList_[*temp] = READ;
        temp++;
    }
}

bool Conversation::UserExist(string name) {
    set<string> :: iterator temp = members_.begin();
    for (int i = 0; i<(int)members_.size(); i++) {
        if(*temp == name)
            return true;
        temp++;
    }
    return false;
}

bool Conversation::IsRead(string name) {
    return readList_[name] == READ ? true : false;
}


void Conversation::VrtDo(string cmdLine, string activeUsrName)
{
	vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES, 1);
	if (cmdLineTokens[0] == "Write" && cmdLineTokens.size() == 2) // Write
	{
        if (UserExist(activeUsrName)) {
            Message newMes = Message(activeUsrName, cmdLineTokens[1]);
            messages_.push_back(newMes);
            updateTime_ = chrono::system_clock::now();
            set<string> :: iterator temp = members_.begin();
            for (int i = 0; i < (int)members_.size(); i++) {
                readList_[*temp] = UNREAD;
                temp++;
            }
            readList_[activeUsrName] = READ;
        }
		else
            cout << activeUsrName << NOT_IN_THE_CONVERSATION << endl;
	}
    
	else if (cmdLineTokens[0] == "Back" && cmdLineTokens.size() == 1) // Back
	{
        throw;
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
    set<string> :: iterator temp = members_.begin();
    for (int i = 0; i< (int)members_.size(); i++) {
        if(*temp == activeUsrName)
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
    set<string> :: iterator itr = members_.begin();
    cout << PARTICIPANTS_TITLE;
    cout << *itr;
    cout << PARTICIPANT_READ_STATUS;
    itr++;
    for (int i = 1; i < (int)members_.size(); i++) {
        cout << COMMA_SPACE;
        cout << *itr;
        cout << PARTICIPANT_READ_STATUS;
        itr++;
    }
    cout << endl;
}

//**************************************************************************************************
//* function name   :   DisplayMessages
//* Description     :   The function print all the messages in the Conversation.
//* Parameters      :   none.
//* Return value    :   none.
//**************************************************************************************************
void Conversation::DisplayMessages() {
    list<Message>::iterator itr = messages_.begin();
    for (int i = 0; i < (int)messages_.size(); i++) {
        (*itr).Print();
    }
}


void Conversation::Help() const
{
	cout << "Write <message>" << endl;
	cout << "Back" << endl;
}
