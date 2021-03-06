#include "MessageBox.h"
#include <iostream>
using namespace std;


MessageBox::MessageBox(string user_name) : user_name_(user_name){
    conversations_ = *new list<MySharedPtr<Conversation>>;
};

//**************************************************************************************************
//* function name   :   isRep
//* Description     :   find if there are repetitions in a given string vector.
//* Parameters      :   a string vector reference.
//* Return value    :   true if found repetition. otherwise false.
//**************************************************************************************************
bool MessageBox::isRep(vector<string> &names){
    sort (names.begin(), names.end());
    for (int i=0; i < names.size() - 1; i++)
        if (names[i] == names[i+1])
            return false;
    return true;
}

//**************************************************************************************************
//* function name   :   allUsersExist
//* Description     :   find if all user names exsists in chatNet.
//* Parameters      :   a string vector reference.
//* Return value    :   true if all users exist. otherwise false.
//**************************************************************************************************
bool MessageBox::allUsersExist(vector<string> &names){
   
}

//**************************************************************************************************
//* function name   :   add
//* Description     :   add conversation or print error message, based on found.
//* Parameters      :   boolean that indicates if all names are users.
//*                     string that contains all the participants names - seperated by space.
//* Return value    :   nothing (void function).
//**************************************************************************************************
void MessageBox::add(bool found, string names){
    if (found)
        conversations_.push_back(*new MySharedPtr<Conversation>(new Conversation(StringSplit(names, BLANK_SPACES))));
    else
        cout << CONVERSATION_FAIL_NO_USER << endl;
}

//**************************************************************************************************
//* function name   :   vec2str
//* Description     :   create a string from a vector indices.
//* Parameters      :   a string vector reference.
//* Return value    :   the new string.
//**************************************************************************************************
string MessageBox::vec2str(vector<string> &strVec){
    string str = "";
    for (int i=0; i < strVec.size(); i++)
        str += strVec[i] + " ";
}

//**************************************************************************************************
//* function name   :   str2num
//* Description     :   turns string to int.
//* Parameters      :   a string.
//* Return value    :   returns -1 if there are none digit chars. returns the number otherwise.
//**************************************************************************************************
int MessageBox::str2num(string str){
    int num = 0;
    for (int i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return -1;
        else
            num += ((int)str[i]) * 10^(str.length() - i - 1);
    return num;
}

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
        else
            throw new CheckAllUsers(vec2str(cmdLineTokens));
	}
	else if (cmdLineTokens[0] == "Open" && cmdLineTokens.size() == 2) // Open
	{
        int conversationNum = str2num(cmdLineTokens[1]);
        if (conversationNum < 1 || conversationNum > conversations_.size())
            cout << INVALID_CONVERSATION_NUMBER << endl;
        else {
            list<MySharedPtr<Conversation>>::iterator itr = conversations_.begin();
            for (int i = 1; i <= conversationNum; i++, itr++);
            (*itr)->Preview(activeUsrName);
            throw new ChangeStatus(vec2str(cmdLineTokens));
        }
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
		if ((*itr)->isRead(activeUsrName)) //* the user did not read the current message
			cout << "(UNREAD) ";
		cout << "Participants: ";
		(*itr)->DisplayParticipants();
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

