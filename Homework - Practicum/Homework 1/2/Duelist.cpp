/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefan Velev
* @idnumber 62537
* @task 2
* @compiler VC
*/

#include <iostream>
#include "Duelist.hpp"

using namespace std;

int own_strlen(const char str[]) {
	int counter = 0;
	while (str[counter++] != '\0');
	--counter;
	return counter;
}

void own_strcpy(char dest[], const char src[])
{
	int counter = 0;
	while (src[counter] != '\0')
		dest[counter] = src[counter++];
	dest[counter] = '\0';
}

Duelist::Duelist(const char* _name) {
	name = new char[own_strlen(_name) + 1];
	own_strcpy(name, _name);
}

Duelist::Duelist(const char* _name, const Deck& _deck) {
	name = new char[own_strlen(_name) + 1];
	own_strcpy(name, _name);
	deck = _deck;
}

Duelist::Duelist(const Duelist& other) {

	this->name = new char[own_strlen(other.name)+1];
	own_strcpy(this->name, other.name);
	this->deck = other.deck;
}

Duelist& Duelist::operator=(const Duelist& other) {
	if (this != &other) {
		delete[] name;
		this->name = new char[own_strlen(other.name) + 1];
		own_strcpy(this->name, other.name);
		this->deck = other.deck;
	}
	return *this;
}


void Duelist::setName(const char* _name) {
	delete[] name;
	name = new char[own_strlen(_name) + 1];
	own_strcpy(name, _name);
}

void Duelist::setDeck(const Deck& _deck) {
	deck = _deck;
}

Duelist::~Duelist() {
	delete[] name;
}

void Duelist::printName() const {
	int size = own_strlen(this->name);
	for (int i = 0; i < size; i++) {
		cout << name[i];
	}
	cout << endl;
}


unsigned int Duelist::getMagicCardCount() const {
	unsigned int counter = 0;

	for (int i = 0; i < MAX_CARDS; i++) {
		if ((deck.magicCards[i].name[0]) != '\0') {
			++counter;
		}
	}
	return counter;
}

unsigned int Duelist::getMonsterCardCount() const {
	unsigned int counter = 0;

	for (int i = 0; i < MAX_CARDS; i++) {
		if ((deck.monsterCards[i].name[0]) != '\0') {
			++counter;
		}
	}
	return counter;
}

void Duelist::changeMagicCardInDeck(const MagicCard& r) {
	for (int i = 0; i < MAX_CARDS; i++) {
		if ((deck.magicCards[i].name[0]) == '\0') {
			deck.magicCards[i] = r;
			break;
		}
		if (i == 19) {
			cout << "There is not enough space in the deck!" << endl;
		}
	}
}

void Duelist::changeMonsterCardInDeck(const MonsterCard& r) {
	for (int i = 0; i < MAX_CARDS; i++) {
		if ((deck.monsterCards[i].name[0]) == '\0') {
			deck.monsterCards[i] = r;
			break;
		}
		if (i == 19) {
			cout << "There is not enough space in the deck!" << endl;
		}
	}
}

void Duelist::changeMagicCardInDeck(unsigned int index, const MagicCard& r) {
	deck.magicCards[index] = r;
}

void Duelist::changeMonsterCardInDeck(unsigned int index, const MonsterCard& r) {
	deck.monsterCards[index] = r;
}

