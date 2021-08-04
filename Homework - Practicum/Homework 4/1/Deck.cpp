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

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include"Deck.hpp"


using namespace std;

Deck::Deck() {
	this->deckName = "";
}

Deck::Deck(string _deckName) {
	this->deckName = _deckName;
}


Deck::Deck(const Deck& other) {
	this->deckName = other.deckName;
	for (int i = 0; i < other.cards.size(); i++) {
		this->addCard(other.cards[i]);
	}
}

void Deck::setCards(const vector<Card*>& _cards) {
	this->cards = _cards;
}

Deck& Deck::operator=(const Deck& rhs) {
	if (this != &rhs) {
		this->clearDeck();

		this->deckName = rhs.deckName;
		for (int i = 0; i < rhs.cards.size(); i++) {
			this->addCard(rhs.cards[i]);
		}
	}
	return *this;
}

string Deck::getDeckName() const {
	return this->deckName;
}

vector<Card*> Deck::getCards() const {
	return this->cards;
}

unsigned int Deck::getNumberOfMonsterCards() const {

	if (this->cards.empty()) {
		return 0;
	}

	int number = 0;

	for (int i = 0; i < this->cards.size(); i++) {
		MonsterCard* monsterCard = dynamic_cast<MonsterCard*>(this->cards[i]);
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(this->cards[i]);
		if (monsterCard && !pendulumCard) {
			++number;
		}
	}

	return number;
}

unsigned int Deck::getNumberOfMagicCards() const {

	if (this->cards.empty()) {
		return 0;
	}

	int number = 0;

	for (int i = 0; i < this->cards.size(); i++) {
		MagicCard* magicCard = dynamic_cast<MagicCard*>(this->cards[i]);
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(this->cards[i]);
		if (magicCard && !pendulumCard) {
			++number;
		}
	}

	return number;
}

unsigned int Deck::getNumberOfPendulumCards() const {

	if (this->cards.empty()) {
		return 0;
	}

	int number = 0;

	for (int i = 0; i < this->cards.size(); i++) {
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(this->cards[i]);
		if (pendulumCard) {
			++number;
		}
	}

	return number;
}

unsigned int Deck::getNumberOfCards() const {
	return (this->getNumberOfMonsterCards() + this->getNumberOfMagicCards() + this->getNumberOfPendulumCards());
}


bool Deck::addCard(Card* _card) {
	if (_card != nullptr) {
		MonsterCard* monsterCard = dynamic_cast<MonsterCard*>(_card);
		MagicCard* magicCard = dynamic_cast<MagicCard*>(_card);
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(_card);

		if (pendulumCard) {

			for (int i = 0; i < this->cards.size(); i++) {
				PendulumCard* pendulumCardCheck = dynamic_cast<PendulumCard*> (this->cards[i]);

				if (pendulumCardCheck) {
					if (pendulumCardCheck->getName() == pendulumCard->getName()) {
						return false;
					}
				}
			}

			this->cards.push_back(_card->clone());
			return true;
		}

		if (monsterCard) {

			for (int i = 0; i < this->cards.size(); i++) {
				MonsterCard* monsterCardCheck = dynamic_cast<MonsterCard*>(this->cards[i]);
				PendulumCard* pendulumCardCheck = dynamic_cast<PendulumCard*> (this->cards[i]);

				if (monsterCardCheck && !pendulumCardCheck) {
					if (monsterCardCheck->getName() == monsterCard->getName()) {
						return false;
					}
				}
			}


			this->cards.push_back(_card->clone());
			return true;
		}

		if (magicCard) {

			for (int i = 0; i < this->cards.size(); i++) {
				MagicCard* magicCardCheck = dynamic_cast<MagicCard*>(this->cards[i]);
				PendulumCard* pendulumCardCheck = dynamic_cast<PendulumCard*> (this->cards[i]);

				if (magicCardCheck && !pendulumCardCheck) {
					if (magicCardCheck->getName() == magicCard->getName()) {
						return false;
					}
				}
			}


			this->cards.push_back(_card->clone());
			return true;
		}
	}
}

void Deck::setDeckName(string _deckName) {
	this->deckName = _deckName;
}

bool Deck::setCard(unsigned int index, Card* _card) {
	if (index >= this->cards.size()) {
		return false;
	}

	MonsterCard* _monsterCard = dynamic_cast<MonsterCard*>(this->cards[index]);
	MagicCard* _magicCard = dynamic_cast<MagicCard*>(this->cards[index]);
	PendulumCard* _pendulumCard = dynamic_cast<PendulumCard*>(this->cards[index]);

	if (_monsterCard && ! _pendulumCard) {
		MonsterCard* monsterCard = dynamic_cast<MonsterCard*>(_card);
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*> (_card);

		if (monsterCard && !pendulumCard) {
			for (int i = 0; i < this->cards.size(); i++) {
				MonsterCard* monsterCardCheck = dynamic_cast<MonsterCard*>(this->cards[i]);
				PendulumCard* pendulumCardCheck = dynamic_cast<PendulumCard*> (this->cards[i]);

				if (monsterCardCheck && !pendulumCardCheck) {
					if (monsterCardCheck->getName() == monsterCard->getName()) {
						return false;
					}
				}
			}

			delete this->cards[index];
			this->cards[index] = monsterCard->clone();
			return true;
		}
	}

	if (_magicCard && !_pendulumCard) {
		MagicCard* magicCard = dynamic_cast<MagicCard*>(_card);
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*> (_card);

		if (magicCard && !pendulumCard) {
			for (int i = 0; i < this->cards.size(); i++) {
				MagicCard* magicCardCheck = dynamic_cast<MagicCard*>(this->cards[i]);
				PendulumCard* pendulumCardCheck = dynamic_cast<PendulumCard*> (this->cards[i]);

				if (magicCardCheck && !pendulumCardCheck) {
					if (magicCardCheck->getName() == magicCard->getName()) {
						return false;
					}
				}
			}

			delete this->cards[index];
			this->cards[index] = magicCard->clone();
			return true;
		}
	}

	if (_pendulumCard) {
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(_card);

		if (pendulumCard) {
			for (int i = 0; i < this->cards.size(); i++) {
				PendulumCard* pendulumCardCheck = dynamic_cast<PendulumCard*> (this->cards[i]);

				if (pendulumCardCheck) {
					if (pendulumCardCheck->getName() == pendulumCard->getName()) {
						return false;
					}
				}
			}

			delete this->cards[index];
			this->cards[index] = pendulumCard->clone();
			return true;
		}
	}
}

void Deck::clearDeck() {
	this->deckName.clear();
	for (int i = 0; i < this->cards.size(); i++) {
		delete this->cards[i];
	}
	this->cards.clear();
}

void Deck::printDeck() const {

	if (this->getNumberOfMonsterCards() == 0 && this->getNumberOfMagicCards() == 0 && this->getNumberOfMonsterCards() == 0) {
		cout << "The deck is empty!" << endl;
		return;
	}

	for (int i = 0; i < this->cards.size(); i++) {
		this->cards[i]->print();
		cout << endl;
	}
}
Deck::~Deck() {
	for (int i = 0; i < this->cards.size(); i++) {
		delete this->cards[i];
	}
}

int random(int i) {
	return rand() % i;
}

void Deck::shuffle() {
	srand(unsigned(time(0)));
	random_shuffle(this->cards.begin(), this->cards.end(), random);
}