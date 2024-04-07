// LoginSystem.h


#ifndef LOGINSYSTEM_H
#define LOGINSYSTEM_H

#include "UserManager.h"
using namespace std;

class LoginSystem {
public:
    LoginSystem(UserManager& userManager);

    bool login(const string& role, string& loggedInUsername);

    string generateRandomCode() const;
    UserManager& userManager;
};

#endif 
