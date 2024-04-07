// Student.cpp
// Zeynep Bedia Gül Ayan 2204012287
// Hasan Gündüz 2104010029

#include "Student.h"
#include <sstream>
#include <iostream>

using namespace std;

Student::Student(const string& username, const string& transcript)
    : User(username, "", "student"), transcript(transcript) {
}

const string& Student::getTranscript() const {
    return transcript;
}

void Student::calculateGPA() const {
    istringstream transcriptStream(transcript);
    string courseData;

    //initialize overall grades to 0 (DEFAULT ARGUMENT)
    double overallQuizScore = 0.0, overallMidtermScore = 0.0, overallProjectScore = 0.0, overallFinalScore = 0.0;
    int numCourses = 0;

    while (getline(transcriptStream, courseData, '*')) {
        
        istringstream courseStream(courseData);
        string courseName, quiz, midterm, project, final;

        //reading course name (it's right before '-Quiz_1')
        getline(courseStream, courseName, '-');

        getline(courseStream, quiz, ':');
        double quizScore, midtermScore, projectScore, finalScore;
        char slash;

        courseStream >> ws; 
        courseStream >> quizScore >> slash;
        courseStream.ignore(numeric_limits<streamsize>::max(), ':'); 
        courseStream >> ws; 
        courseStream >> midtermScore >> slash;
        courseStream.ignore(numeric_limits<streamsize>::max(), ':'); //ignore characters until ':'
        courseStream >> ws; //skip leading whitespaces
        courseStream >> projectScore >> slash;
        courseStream.ignore(numeric_limits<streamsize>::max(), ':'); 
        courseStream >> ws; 
        courseStream >> finalScore;

        // summing up grades for overall GPA calculation
        overallQuizScore += quizScore;
        overallMidtermScore += midtermScore;
        overallProjectScore += projectScore;
        overallFinalScore += finalScore;

        double gpa = (quizScore * 0.1) + (midtermScore * 0.2) + (projectScore * 0.3) + (finalScore * 0.4);
        cout << "GPA for " << courseName << ": " << gpa << " out of 100\n";

        numCourses++;
    }

    //calculate overall GPA
    double overallGPA = ((overallQuizScore / numCourses) * 0.1) +
                        ((overallMidtermScore / numCourses) * 0.2) +
                        ((overallProjectScore / numCourses) * 0.3) +
                        ((overallFinalScore / numCourses) * 0.4);

    cout << "Overall GPA for " << getUsername() << ": " << overallGPA << " out of 100\n";
}
