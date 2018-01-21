#ifndef _MESSAGEBOX_H_
#define _MESSAGEBOX_H_


#include <list>
#include "ObjectInterface.h"
#include "Conversation.h"

class MessageBox : public ObjectInterface {
public:
    void VrtDo(string cmd, string activeUsrName);
    void Preview(string activeUsrName);
    void Help() const;
private:
    MessageBox(); // constructor
    
    
    list<Conversation> conversations_; // conversations list
    string user_name_; // user name of the messageBox owner
};

#endif
