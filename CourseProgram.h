// CourseProgram.h


#ifndef COURSEPROGRAM_H
#define COURSEPROGRAM_H

#include <string>
#include <map>
using namespace std;

class CourseProgram {
public:
    //static member function
    static map<string, string> loadFromFile(const string& filePath);
    static void display(const string& section);

private:
    //static member variable
    static map<string, string> coursePrograms;
};

#endif 
