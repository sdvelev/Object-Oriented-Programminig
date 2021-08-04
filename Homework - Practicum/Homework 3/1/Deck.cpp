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

#include<iostream>
#include<string>
#include<vector>
#include"Deck.hpp"

using namespace std;

Deck::Deck() {
	this->deckName = "";
}

Deck::Deck(string _deckName) {
	this->deckName = _deckName;
}

Deck::Deck(string _deckName, vector<MonsterCard> _monsterCards, vector<MagicCard> _magicCards,
	vector<PendulumCard> _pendulumCards) {
	this->deckName = _deckName;
	this->monsterCards = _monsterCards;
	this->magicCards = _magicCards;
	this->pendulumCards = _pendulumCards;
}

string Deck::getDeckName() const {
	return this->deckName;
}

vector<MonsterCard> Deck::getMonsterCards() const {
	return this->monsterCards;
}

vector<MagicCard> Deck::getMagicCards() const {
	return this->magicCards;
}

vector<PendulumCard> Deck::getPendulumCards() const {
	return this->pendulumCards;
}

unsigned int Deck::getNumberOfMonsterCards() const {
	if (!this->monsterCards.empty()) {
		return this->monsterCards.size();
	}
	else {
		return 0;
	}
}

unsigned int Deck::getNumberOfMagicCards() const {
	
	if (!this->magicCards.empty()) {
		return this->magicCards.size();
	}
	else {
		return 0;
	}
}

unsigned int Deck::getNumberOfPendulumCards() const {
	
	if (!this->pendulumCards.empty()) {
		return this->pendulumCards.size();
	}
	else {
		return 0;
	}
}

void Deck::addMonsterCard(const MonsterCard& _monsterCard) {
	this->monsterCards.push_back(_monsterCard);
}

void Deck::addMagicCard(const MagicCard& _magicCard) {
	this->magicCards.push_back(_magicCard);
}

void Deck::addPendulumCard(const PendulumCard& _pendulumCard) {
	this->pendulumCards.push_back(_pendulumCard);
}

void Deck::setDeckName(string _deckName) {
	this->deckName = _deckName;
}

void Deck::setMonsterCard(unsigned int index, const MonsterCard& _monsterCard) {
	if (index >= this->monsterCards.size()) {
		return;
	}
	this->monsterCards[index] = _monsterCard;
}

void Deck::setMagicCard(unsigned int index, const MagicCard& _magicCard) {
	if (index >= this->magicCards.size()) {
		return;
	}
	this->magicCards[index] = _magicCard;
}

void Deck::setPendulumCard(unsigned int index, const PendulumCard& _pendulumCard) {

	if (index >= this->pendulumCards.size()) {
		return;
	}
	this->pendulumCards[index] = _pendulumCard;
}

void Deck::clearDeck() {
	this->deckName.clear();
	this->monsterCards.clear();
	this->magicCards.clear();
	this->pendulumCards.clear();
}

void Deck::printDeck() const {
	
	if (this->getNumberOfMonsterCards() == 0 && this->getNumberOfMagicCards() == 0 && this->getNumberOfMonsterCards() == 0) {
		cout << "The deck is empty!" << endl;
		return;
	}
	
	if (this->getNumberOfMonsterCards() > 0) {
		cout << "**Monster Cards**" << endl;
		cout << "Number of Monster Cards: " << this->getNumberOfMonsterCards() << endl;
		for (int i = 0; i < this->monsterCards.size(); i++) {
			this->monsterCards[i].print();
		}

		if (this->getNumberOfMagicCards() > 0) {
			cout << endl;
		}
	}

	if (this->getNumberOfMagicCards() > 0) {
		cout << "**Magic Cards**" << endl;
		cout << "Number of Magic Cards: " << this->getNumberOfMagicCards() << endl;
		for (int i = 0; i < this->magicCards.size(); i++) {
			this->magicCards[i].print();
		}

		if (this->getNumberOfPendulumCards() > 0) {
			cout << endl;
		}
	}

	if (this->getNumberOfPendulumCards() > 0) {
		cout << "**Pendulum Cards**" << endl;
		cout << "Number of Pendulum Cards: " << this->getNumberOfPendulumCards() << endl;
		for (int i = 0; i < this->pendulumCards.size(); i++) {
			this->pendulumCards[i].print();
		}
	}

}