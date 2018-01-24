#ifndef _USER_H_
#define _USER_H_

#include "MessageBox.h"
#include "ObjectInterface.h"

// ------------------------------- User ------------------------------- //
class User : public ObjectInterface {
    // ------------------------------- Methods ------------------------------------ //
public:
    //**************************************************************************************************
    //* function name   :   User
    //* Description     :   Constuct new User obj.
    //* Parameters      :   mane of the user, password of user, messagebox of the user
    //* Return value    :   none.
    //**************************************************************************************************
    User(string name, string password, MessageBox messageBox) : name_(name), password_(password), messageBox_(messageBox) {};

    //**************************************************************************************************
    //* function name   :   Preview
    //* Description     :   if the user is part of the conversation we will print it on the screen.
    //* Parameters      :   the name of the active user.
    //* Return value    :   none.
    //**************************************************************************************************
    void Preview(string activeUsrName);

    //**************************************************************************************************
    //* function name   :   VrtDo
    //* Description     :   the function get the command and execute it. there are two commands: Write and Back.
    //* Parameters      :   cmd- the command
    //*                     activeUsrName - the name of the user
    //* Return value    :   none.
    //**************************************************************************************************
    void VrtDo(string cmd, string activeUsrName);

    //**************************************************************************************************
    //* function name   :   getUserName
    //* Description     :   the function returns the user name.
    //* Parameters      :   none.
    //* Return value    :   the user name of the current user.
    //**************************************************************************************************
    string getUserName() const;
    
    
    MessageBox* getMessageBox() ;
    
    
    void Help() const;
    // ------------------------------- Properties ------------------------------------ //
private:
    string name_;
    string password_;
    MessageBox messageBox_;
};



// ------------------------------- Admin ------------------------------- //
class Admin : public User {
    // ------------------------------- Methods ------------------------------------ //
public:
    //**************************************************************************************************
    //* function name   :   User
    //* Description     :   Constuct new User obj.
    //* Parameters      :   mane of the user, password of user, messagebox of the user
    //* Return value    :   none.
    //**************************************************************************************************
    Admin(string name, string password, MessageBox messageBox);
    
    
    //**************************************************************************************************
    //* function name   :   VrtDo
    //* Description     :   the function get the command and execute it. there are two commands: Write and Back.
    //* Parameters      :   cmd- the command
    //*                     activeUsrName - the name of the user
    //* Return value    :   none.
    //**************************************************************************************************
    void VrtDo(string cmd, string activeUsrName);
    

    void Help() const;
    
    
    // ------------------------------- Properties ------------------------------------ //
private:
   
};


#endif


