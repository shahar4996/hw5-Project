#include <iostream>
#include <stdexcept>
#include "Conversation.h"
#include "ChatNet.h"
#include "Defs.h"

#define NO_ACTIVE_USER "No User"

typedef list<MySharedPtr<Conversation>> ConvList;

//**************************************************************************************************
//* function name   :   checkUsers
//* Description     :   checks if all users specified in the given vector are registerd at chatNet.
//* Parameters      :   users - string vector.
//* Return value    :   returns true if all users exists. otherwise returns false.
//**************************************************************************************************
bool ChatNet::checkUsers(vector<string> users){
    for (int i = 1; i < users.size(); i++)
       if(users_.find(users[i]) == users_.end())
        //if(find(users_.begin(), users_.end(), users.at(i)) == users_.end())
            return false;
    return true;
}

//**************************************************************************************************
//* function name   :   findUser
//* Description     :   return user object that has the specified user name.
//* Parameters      :   userName - the wanted user name.
//* Return value    :   returns the user that has the specified user name. if not found returns NULL.
//**************************************************************************************************
User* ChatNet::findUser(string userName){
    return nullptr;
}

// Interface
ChatNet::ChatNet(const string& networkName, const string& adminName, const string& adminPass){
    
}




void ChatNet::VrtDo(string cmdLine, string activeUsrName)
{
    vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES);
    if (cmdLineTokens[0] == "Login" && cmdLineTokens.size() == 3) // Login
    {
        // add code here
    }
    else if (cmdLineTokens[0] == "New" && cmdLineTokens.size() == 3) // New
    {
        // add code here
    }
    else if (cmdLineTokens[0] == "Exit" && cmdLineTokens.size() == 1) // Exit
    {
        throw BackSignal();
    }
    else // INVALID_INPUT
        cout << INVALID_INPUT;
}

void ChatNet::Do(string cmd)
{
    try
    {
        // Call Do method of the currently active object.
        // When using stack (from STL) this could like something like the following line:
        // activeObjectStack_.top().Do(cmd, activeUsrName_);
    }
    catch (CheckAllUsersExeption ex)
    {
        activeObjectStack_.top().add(checkUsers(ex.getNames()),ex.getNames());
    }
    catch (OpenConversationExeption ex)
    {
        string userName = ex.getUserName();
        int conversationNum = ex.getConversationNum();
        ConvList *conversations = findUser(userName)->getMessageBox()->getConversations();
        ConvList::iterator itr = (*conversations).begin();
        for (int i = 1; i <= conversationNum; i++, itr++);
        activeObjectStack_.push(*itr->get());
        (*itr)->Preview(userName);
    }
    catch (SearchExeption ex)
    {
        bool found_flag = false;
        sort(users_.begin(), users_.end());
        list<string>::iterator itr = users_.begin();
        for (; itr != users_.end(); itr++){
            if (itr->find(ex.getStr())) {
                if (!found_flag)
                    cout << SEARCH_FOUND_TITLE << endl;
                found_flag = true;
                cout << *itr << endl;
            }
        }
        if (!found_flag)
            cout << SEARCH_NOT_FOUND_TITLE << endl;
    }
    catch (BackExeption ex){
        activeObjectStack_.pop();
        activeObjectStack_.top().Preview();
    }
}


void ChatNet::Preview(string activeUsrName)
{
    cout << "Welcome to " << networkName_ << "." << endl;
}


void ChatNet::Help() const
{
    cout << "Login <user name> <password>" << endl;
    cout << "New <user name> <password>" << endl;
    cout << "Exit" << endl;
}

