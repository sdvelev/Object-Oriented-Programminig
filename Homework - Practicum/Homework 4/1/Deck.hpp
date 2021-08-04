/**
* Solution to homework assignment 4
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
#include"MonsterCard.hpp"
#include"MagicCard.hpp"
#include"PendulumCard.hpp"

using namespace std;

class Deck {
private:
	string deckName;
	vector<Card*> cards;
public:
	Deck();
	Deck(string _deckName);

	Deck(const Deck& other);
	Deck& operator=(const Deck& rhs);

	string getDeckName() const;
	vector<Card*> getCards() const;

	unsigned int getNumberOfMonsterCards() const;
	unsigned int getNumberOfMagicCards() const;
	unsigned int getNumberOfPendulumCards() const;

	unsigned int getNumberOfCards() const;

	bool addCard(Card* _card);

	void setDeckName(string _deckName);

	void setCards(const vector<Card*>& _cards);

	bool setCard(unsigned int index, Card* _card);

	void printDeck() const;

	void clearDeck();

	void shuffle();

	~Deck();
};