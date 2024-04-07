// Student.h


#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <string>
#include <vector>

//INHERITANCE
class Student : public User {
public:
    Student(const string& username, const string& transcript);
    const string& getTranscript() const;
    void calculateGPA() const; 

private:
    string transcript;
    vector<double> courseGPAs;  
};

#endif 
