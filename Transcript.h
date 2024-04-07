// Transcript.h

#ifndef TRANSCRIPT_H
#define TRANSCRIPT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Transcript {
public:
    Transcript();

    void loadFromFile(const string& filePath);
    void display() const;

private:
    vector<string> transcriptData;
};

#endif 
