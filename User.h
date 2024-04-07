// User.h


#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

class User {
public:
    User(const string& username, const string& password, const string& role);

    const string& getUsername() const;
    bool checkPassword(const string& inputPassword) const;
    const string& getRole() const;
    const string& getPassword() const;

    //Function Overloading
    void displayUserInfo() const;

    //Operator Overloading
    bool operator==(const User& other) const;

    // Static Variable
    static int totalUsers;

    //Friend Function Declaration
    friend void compareUsers(const User& user1, const User& user2);

private:
    string username;
    string password;
    string role;
};

#endif
