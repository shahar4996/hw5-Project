#ifndef _MESSAGEBOX_H_
#define _MESSAGEBOX_H_


#include <list>
#include "ObjectInterface.h"
#include "Conversation.h"
#include "MySharedPtr.h"

class MessageBox : public ObjectInterface {
public:
    MessageBox(string user_name); // constructor
    void VrtDo(string cmd, string activeUsrName);
    void Preview(string activeUsrName);
    void Help() const;
private:
    list<MySharedPtr<Conversation>> conversations_; // conversations list
    string user_name_; // user name of the messageBox owner
};

#endif
