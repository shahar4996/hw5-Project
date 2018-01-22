#include "MessageBox.h"
#include <iostream>
using namespace std;


MessageBox::MessageBox(string user_name) : user_name_(user_name){
    conversations_ = *new list<MySharedPtr<Conversation>>;
};


//Interface


void MessageBox::VrtDo(string cmdLine, string activeUsrName)
{
	size_t idx;
	vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES);
	if (cmdLineTokens[0] == "New" && cmdLineTokens.size() > 1) // New
	{
        cmdLineTokens.erase(cmdLineTokens.begin());
        if(isRep(cmdLineTokens))
           cout << CONVERSATION_FAIL_USER_REPETITION << endl;
        else if(allUsersExist(cmdLineTokens))
           cout << CONVERSATION_FAIL_NO_USER << endl;
        else{
            set<User> users = vec2set(cmdLineTokens);
            MySharedPtr<Conversation> conversation = new MySharedPtr<Conversation>(*users);
            conversations_.push_front(conversation);
            
            
           }
           
           
	}
	else if (cmdLineTokens[0] == "Open" && cmdLineTokens.size() == 2) // Open
	{
		// add code here
	}
	else if (cmdLineTokens[0] == "Delete" && cmdLineTokens.size() == 2) // Delete
	{
		// add code here
	}
	else if (cmdLineTokens[0] == "Search" && cmdLineTokens.size() == 2) // Search
	{
		// add code here
	}
	else if (cmdLineTokens[0] == "Back") // Back
	{
		// add code here
	}
	else // INVALID_INPUT
        cout << INVALID_INPUT;
}

//**************************************************************************************************
//* function name   :   Preview
//* Description     :   prints all conversations partners and prints if the specific user has read the
//*                     message.
//* Parameters      :   the wanted user name
//* Return value    :   nothing (void function).
//**************************************************************************************************
void MessageBox::Preview(string activeUsrName)
{
	int count = 1;
	if (conversations_.empty()) // There are no conversations in MessageBox
		cout << "No conversations" << endl;
	else
		cout << "Conversations:" << endl;
   
    list<MySharedPtr<Conversation>>::iterator itr = conversations_.begin();
    for (; itr != conversations_.end(); itr++) // iterate over conversations with iterator called itr
	{
		cout << count << ") ";
		if (itr->isRead(activeUsrName)) //* the user did not read the current message
			cout << "(UNREAD) ";
		cout << "Participants: ";
		itr->DisplayParticipants();
		++count;
	}
}


void MessageBox::Help() const
{
	cout << "New <user names separated by spaces>" << endl;
	cout << "Open <conversation number>" << endl;
	cout << "Delete <conversation number>" << endl;
	cout << "Search <partial user name>" << endl;
	cout << "Back" << endl;
}

