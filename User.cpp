//User.cpp
// Zeynep Bedia Gül Ayan 2204012287
// Hasan Gündüz 2104010029

#include "User.h"
using namespace std;

//initialize static variable
int User::totalUsers = 0;

User::User(const string& username, const string& password, const string& role)
    : username(username), password(password), role(role) {

        totalUsers++;
}

const string& User::getUsername() const {
    return username;
}

bool User::checkPassword(const string& inputPassword) const {
    return inputPassword == password;
}

const string& User::getRole() const {
    return role;
}

const string& User::getPassword() const {
    return password;
}

//function Overloading
void User::displayUserInfo() const {
    cout << "Username: " << username << endl;
    cout << "Role: " << role << endl;
}

//operator overloading
bool User::operator==(const User& other) const {
    return username == other.username && password == other.password && role == other.role;
}

//Friend Function 
void compareUsers(const User& user1, const User& user2) {
    if (user1.role == user2.role) {
        cout << "Users have the same role." << endl;
    }
    else {
        cout << "Users have different roles." << endl;
    }
}
