/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 1
* @compiler VC
*/


#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Deck.hpp"

using namespace std;

class Duelist {
private:
	string duelistName;
	Deck duelistDeck;
public:
	Duelist();
	Duelist(string _duelistName);
	Duelist(string _duelistName, const Deck& _duelistDeck);

	string getDuelistName() const;

	void setDuelistName(string _duelistName);
	void setDuelistDeck(const Deck& _duelistDeck);

	Deck& getDeck();
	bool saveDeck(string fileName);
	bool loadDeck(string fileName);

	void display() const;
};