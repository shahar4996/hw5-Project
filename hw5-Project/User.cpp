#include<iostream>
#include "User.h"


// ------------------------------- User ------------------------------- //

//**************************************************************************************************
//* function name   :   getMessageBox
//* Description     :   the function returns the message box.
//* Parameters      :   none.
//* Return value    :   the message box of the current user.
//**************************************************************************************************
MessageBox* User::getMessageBox() { return &messageBox_; };

// Interface


void User::VrtDo(string cmdLine, string activeUsrName)
{
    vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES);
    if (cmdLineTokens[0] == "Messages" && cmdLineTokens.size() == 1) // Messages
    {
        throw; // need to return exeption so we will get into messagebox;
    }
    else if (cmdLineTokens[0] == "Logout" && cmdLineTokens.size() == 1) // Logout
    {
        throw;  // need to return exeption so we will get back to login;
    }
    else // INVALID_INPUT
        cout << INVALID_INPUT;
}


void User::Preview(string activeUsrName) {
    cout << USER_PREVIEW_PART1;
    if (messageBox_.readAll()) // Omri's
        cout << USER_PREVIEW_PART2_NO_MESSAGES;
    else
        cout << USER_PREVIEW_PART2_NEW_MESSAGES;
}



void User::Help() const
{
    cout << "Messages" << endl;
    cout << "Logout" << endl;
}









// ------------------------------- Admin ------------------------------- //
void Admin::VrtDo(string cmdLine, string activeUsrName)
{
    vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES);
    if (cmdLineTokens[0] == "New" && cmdLineTokens.size() == 3) // New
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
    else // User command
    {
        // add code here
    }
}

void Admin::Help() const
{
    cout << "New <admin name> <admin password>" << endl;
    cout << "Delete <user name>" << endl;
    cout << "Search <partial user name>" << endl;
    User::Help(); // User commands
}

