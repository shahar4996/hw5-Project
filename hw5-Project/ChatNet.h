#ifndef _SOCIAL_NET_H_
#define _SOCIAL_NET_H_

#include <stack>
#include "Defs.h"
#include "ObjectInterface.h"
#include "User.h"
#include <stack>



class ChatNet : public ObjectInterface {
    //---------------------------Methods---------------------------//
public:
    // constructor
    ChatNet(const string& networkName, const string& adminName, const string& adminPass);
    
    // Virtual Function Override
    void VrtDo(string cmdLine, string activeUsrName);
    void Do(string cmd);
    void Preview(string activeUsrName);
    void Help() const;
    
    
    //---------------------------Properties---------------------------//
private:
    stack<ObjectInterface> activeObjectStack_;
    string networkName_;
    string currentUser_;
    stack<ObjectInterface> ActiveObjStack_;
    map<string, MySharedPtr<User>> users_;
    
    bool checkUsers(vector<string> users);
    User* findUser(string userName);
};


#endif

