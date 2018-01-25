#ifndef _SOCIAL_NET_H_
#define _SOCIAL_NET_H_

#include <stack>
#include "Defs.h"
#include "ObjectInterface.h"
#include "User.h"



class ChatNet : public ObjectInterface {
public:
	ChatNet(const string& networkName, const string& adminName, const string& adminPass);
    void VrtDo(string cmdLine, string activeUsrName);
    void Do(string cmd);
    void VrtPreview(string activeUsrName);
    void Help() const;
    
private:
    stack<ObjectInterface> activeObjectStack_;
    string networkName_;
    string adminName_;
    string adminPass_;
    list<string> users_;
    
    bool checkUsers(vector<string> users);
    User* findUser(string userName);
};


#endif

