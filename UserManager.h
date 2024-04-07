// UserManager.h
// Zeynep Bedia Gül Ayan 2204012287
// Hasan Gündüz 2104010029

#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Student.h"
#include "User.h"
using namespace std;

class UserManager {
public:
    UserManager();

    bool addUser(const string& username, const string& password, const string& role);
    User* findUser(const string& username, const string& role);

    const vector<User>& getUsers() const;
    const vector<Student>& getStudents() const;

    const Student& getStudent(const string& username) const;

    bool isPasswordValid(const string& password) const;
    bool isUsernameValid(const string& username) const;

    void readFromFiles();
    void saveToFile(const string& role, const User& user) const;

    bool addStaffUser(const string& username, const string& password);

    Student& getStudent(const string& username);

    void sortUsers();

private:
    vector<User> users;
    vector<Student> students;
};

#endif

