#include<iostream>
#include "User.h"


// ------------------------------- User ------------------------------- //



// Interface


void User::VrtDo(string cmdLine, string activeUsrName)
{
    vector<string> cmdLineTokens = StringSplit(cmdLine, BLANK_SPACES);
    if (cmdLineTokens[0] == "Messages" && cmdLineTokens.size() == 1) // Messages
    {
        throw new UserExeption("Messages"); // need to return exeption so we will get into messagebox;
    }
    else if (cmdLineTokens[0] == "Logout" && cmdLineTokens.size() == 1) // Logout
    {
        throw new UserExeption("Logout");  // need to return exeption so we will get back to login;
    }
    else // INVALID_INPUT
        cout << INVALID_INPUT;
}


void User::Preview(string activeUsrName) {
    cout << USER_PREVIEW_PART1;
    if (true)//messageBox_.readAll()) // Omri's
        cout << USER_PREVIEW_PART2_NO_MESSAGES;
    else
        cout << USER_PREVIEW_PART2_NEW_MESSAGES;
}

MessageBox* User::getMessageBox() {
    return &messageBox_;
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
        throw new UserExeption("New", cmdLineTokens[1], cmdLineTokens[2]);
    }
    else if (cmdLineTokens[0] == "Delete" && cmdLineTokens.size() == 2) // Delete
    {
        throw new UserExeption("Delete", cmdLineTokens[1]);
    }
    else if (cmdLineTokens[0] == "Search" && cmdLineTokens.size() == 2) // Search
    {
        throw new UserExeption("Search", cmdLineTokens[1]);
    }
    else // User command
    {
        this->User::VrtDo(cmdLine, activeUsrName);
    }
}

void Admin::Help() const
{
    cout << "New <admin name> <admin password>" << endl;
    cout << "Delete <user name>" << endl;
    cout << "Search <partial user name>" << endl;
    User::Help(); // User commands
}

