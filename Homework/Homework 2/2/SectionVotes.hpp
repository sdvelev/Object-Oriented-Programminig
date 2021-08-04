
#pragma once
#include<iostream>


using namespace std;
// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes
{
private:
    int votesParty1;
    int votesParty2;
    int votesParty3;
public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;
    friend ostream& operator<<(ostream& out, const SectionVotes& other);
    friend istream& operator>>(istream& in, SectionVotes& other);

    int getVotesForParty1() const;
    int getVotesForParty2() const;
    int getVotesForParty3() const;

};