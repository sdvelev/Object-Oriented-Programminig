
#pragma once
#include<iostream>
#include<string>
#include"SectionVotes.hpp"

using namespace std;
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

class ElectionResultsDatabase
{
private:
    int votesParty1;
    int votesParty2;
    int votesParty3;
    int numberSections;
    string content;

    void addVotes(int _votesParty1, int _votesParty2, int _votesParty3);
    string getContent() const;
    void addToContent(int _votesParty1, int _votesParty2, int _votesParty3);
    void addSection();
public:
    ElectionResultsDatabase();
    ElectionResultsDatabase(int _votesParty1, int _votesParty2, int _votesParty3);

    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    

    Party winningParty() const;

    friend ostream& operator<<(ostream& out, const ElectionResultsDatabase& other);

    friend istream& operator>>(istream& in, ElectionResultsDatabase& other);


};