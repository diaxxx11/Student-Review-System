// Transcript.cpp
// Zeynep Bedia Gül Ayan 2204012287
// Hasan Gündüz 2104010029

#include "Transcript.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std; 

Transcript::Transcript() {
}


void Transcript::loadFromFile(const string& filePath) {
    ifstream transcriptFile("/Users/bedia/Desktop/hasan (xcode)/transcript.txt"); 
    if (transcriptFile.is_open()) {
        string line;
        while (getline(transcriptFile, line)) {
            transcriptData.push_back(line);
        }
        transcriptFile.close();
    }
    else {
        cerr << "Error: Could not open the transcript file." << endl;
    }
}

void Transcript::display() const {
    for (vector<string>::const_iterator it = transcriptData.begin(); it != transcriptData.end(); ++it) {
        cout << *it << endl;
    }
}

