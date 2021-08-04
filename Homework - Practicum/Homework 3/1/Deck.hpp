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
#include"MonsterCard.hpp"
#include"MagicCard.hpp"
#include"PendulumCard.hpp"

using namespace std;

class Deck {
private:
	string deckName;
	vector<MonsterCard> monsterCards;
	vector<MagicCard> magicCards;
	vector<PendulumCard> pendulumCards;
public:
	Deck();
	Deck(string _deckName);
	Deck(string _deckName, vector<MonsterCard> _monsterCards, vector<MagicCard> _magicCards,
		vector<PendulumCard> _pendulumCards);

	string getDeckName() const;
	vector<MonsterCard> getMonsterCards() const;
	vector<MagicCard> getMagicCards() const;
	vector<PendulumCard> getPendulumCards() const;

	unsigned int getNumberOfMonsterCards() const;
	unsigned int getNumberOfMagicCards() const;
	unsigned int getNumberOfPendulumCards() const;

	void addMonsterCard(const MonsterCard& _monsterCard);
	void addMagicCard(const MagicCard& _magicCard);
	void addPendulumCard(const PendulumCard& _pendulumCard);

	void setDeckName(string _deckName);

	void setMonsterCard(unsigned int index, const MonsterCard& _monsterCard);
	void setMagicCard(unsigned int index, const MagicCard& _magicCard);
	void setPendulumCard(unsigned int index, const PendulumCard& _pendulumCard);

	void printDeck() const;

	void clearDeck();
};