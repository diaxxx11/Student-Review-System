// LoginSystem.cpp


#include "LoginSystem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

LoginSystem::LoginSystem(UserManager& userManager) : userManager(userManager) {
    srand(time(0));
}

bool LoginSystem::login(const string& role, string& loggedInUsername) {
    int remainingAttempts = 3;
    string verificationCode;

    while (remainingAttempts > 0) {
        verificationCode = generateRandomCode();

        cout << role << " Username: ";
        string inputUsername;
        cin >> inputUsername;

        User* user = userManager.findUser(inputUsername, role);

        if (user != NULL) {
            cout << "Password: ";
            string inputPassword;
            cin >> inputPassword;

            if (user->checkPassword(inputPassword)) {
                cout << "Enter Verification Code: " << verificationCode << endl;
                string inputCode;
                cin >> inputCode;

                if (inputCode == verificationCode) {
                    cout << "Login successful. Welcome, " << inputUsername << "!" << endl;
                    loggedInUsername = inputUsername;
                    return true;
                }
                else {
                    cout << "Verification code is incorrect. Please try again." << endl;
                }
            }
            else {
                cout << "Incorrect password. Please try again." << endl;
            }
        }
        else {
            cout << "Username not found. Please enter a valid username." << endl;
        }

        remainingAttempts--;
        if (remainingAttempts == 0) {
            cout << "You have exceeded the maximum number of login attempts. Please try again later." << endl;
        }
    }

    return false;
}

string LoginSystem::generateRandomCode() const {
    const string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int codeLength = 4;

    string code;
    for (int i = 0; i < codeLength; i++) {
        int index = rand() % charset.length();
        code += charset[index];
    }

    return code;
}
