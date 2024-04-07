// UserManager.cpp
// Zeynep Bedia Gül Ayan 2204012287
// Hasan Gündüz 2104010029

#include "UserManager.h"
#include "Student.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

UserManager::UserManager() {
    readFromFiles();
}

bool UserManager::addUser(const string& username, const string& password, const string& role) {
    if (!isUsernameValid(username)) {
        cout << "Username is not valid. It must be at least 5 characters long and contain only letters." << endl;
        return false;
    }

    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].getUsername() == username) {
            cout << "Username already exists. Please choose a different username." << endl;
            return false;
        }
    }

    if (!isPasswordValid(password)) {
        cout << "Password is not valid. It must be 5 to 12 characters long and contain at least 1 uppercase letter." << endl;
        return false;
    }

    users.push_back(User(username, password, role));
    saveToFile(role, users[users.size() - 1]);

    cout << "User registration successful." << endl;
    return true;
}

User* UserManager::findUser(const string& username, const string& role) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].getUsername() == username && users[i].getRole() == role) {
            return &users[i];
        }
    }
    return NULL;
}

const vector<User>& UserManager::getUsers() const {
    return users;
}

const vector<Student>& UserManager::getStudents() const {
    return students;
}

const Student& UserManager::getStudent(const string& username) const {
    for (const Student& student : students) {
        if (student.getUsername() == username) {
            return student;
        }
    }
    throw runtime_error("Student not found");
}

bool UserManager::isPasswordValid(const string& password) const {
    if (password.length() < 5 || password.length() > 12) {
        return false;
    }

    bool hasUppercase = false;
    for (size_t i = 0; i < password.length(); ++i) {
        if (isupper(password[i])) {
            hasUppercase = true;
            break;
        }
    }

    return hasUppercase;
}

bool UserManager::isUsernameValid(const string& username) const {
    if (username.length() < 5) {
        return false;
    }

    for (size_t i = 0; i < username.length(); ++i) {
        if (!isalpha(username[i])) {
            return false;
        }
    }

    return true;
}

void UserManager::readFromFiles() {
    ifstream file("/Users/bedia/Desktop/hasan (xcode)/user.txt");
    if (file.is_open()) {
        string username, password, role;
        while (file >> username >> password >> role) {
            users.push_back(User(username, password, role));
            if (role == "student") {
                // Load transcript data for the student from "transcript.txt"
                ifstream transcriptFile("/Users/bedia/Desktop/hasan (xcode)/transcript.txt");
                string transcriptData;
                string line;

                // find the transcript of the current student
                bool foundStudent = false;
                while (getline(transcriptFile, line)) {
                    if (line == username) {
                        foundStudent = true;
                        transcriptData += line + "\n";
                    } else if (foundStudent) {
                        transcriptData += line + "\n";
                    }

                    //check for an empty line
                    if (line.empty()) {
                        if (foundStudent) {
                            break;
                        }
                    }
                }

                students.push_back(Student(username, transcriptData));
                transcriptFile.close();
            }
        }
        file.close();
    } else {
        cout << "Warning: users.txt not found. Creating a new file." << endl;

        ofstream createFile("/Users/bedia/Desktop/hasan (xcode)/user.txt");
        if (createFile.is_open()) {
            cout << "users.txt created successfully." << endl;
            createFile.close();
        } else {
            cout << "Error: Unable to create users.txt." << endl;
        }
    }
}

void UserManager::saveToFile(const string& role, const User& user) const {
    ofstream file("/Users/bedia/Desktop/hasan (xcode)/user.txt", ios::app);
    if (file.is_open()) {
        file << user.getUsername() << " " << user.getPassword() << " " << user.getRole() << endl;
        file.close();
    } else {
        cout << "Error: Unable to open users.txt for writing." << endl;
    }
}

bool UserManager::addStaffUser(const string& username, const string& password) {
    User* staffUser = findUser(username, "Staff");
    if (staffUser == NULL) {
        cout << "Staff user not found. Cannot add a new user." << endl;
        return false;
    }


    return true;
}

Student& UserManager::getStudent(const string& username) {
    for (Student& student : students) {
        if (student.getUsername() == username) {
            return student;
        }
    }
    throw runtime_error("Student not found");
}

void UserManager::sortUsers() {
    //BUBBLE SORT ALGORITHM for simplicity 
    for (size_t i = 0; i < users.size() - 1; ++i) {
        for (size_t j = 0; j < users.size() - i - 1; ++j) {
            if (users[j].getUsername() > users[j + 1].getUsername()) {
                // Swap users[j] and users[j+1]
                User temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
}
