#include<iostream>
#include"SectionVotes.hpp"

using namespace std;

SectionVotes::SectionVotes() {
	this->votesParty1 = 0;
	this->votesParty2 = 0;
	this->votesParty3 = 0;
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes) {
	this->votesParty1 = party1Votes;
	this->votesParty2 = party2Votes;
	this->votesParty3 = party3Votes;
}

int SectionVotes::votesForParty(Party party) const {
	if (party == Party::PARTY1) {
		return this->votesParty1;
	}
	if (party == Party::PARTY2) {
		return this->votesParty2;
	}
	if (party == Party::PARTY3) {
		return this->votesParty3;
	}
}

int SectionVotes::getVotesForParty1() const {
	return this->votesParty1;
}

int SectionVotes::getVotesForParty2() const {
	return this->votesParty2;
}

int SectionVotes::getVotesForParty3() const {
	return this->votesParty3;
}

ostream& operator<<(ostream& out, const SectionVotes& other) {
	out << other.getVotesForParty1() << " " << other.getVotesForParty2() << " " << other.getVotesForParty3() << endl;
	return out;
}

istream& operator>>(istream& in, SectionVotes& other) {
	int votesParty1;
	int votesParty2;
	int votesParty3;
	in >> votesParty1 >> votesParty2 >> votesParty3;
	other = SectionVotes(votesParty1, votesParty2, votesParty3);
	return in;
}
