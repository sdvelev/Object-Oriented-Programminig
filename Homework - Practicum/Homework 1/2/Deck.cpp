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

#include<iostream>
#include "Deck.hpp"

using namespace std;

unsigned int Deck::getMagicCardCount() const {
	unsigned int counter = 0;

	for (int i = 0; i < MAX_CARDS; i++) {
		if ((magicCards[i].name[0]) != '\0') {
			++counter;
		}
	}
	return counter;
}

unsigned int Deck::getMonsterCardCount() const {
	unsigned int counter = 0;

	for (int i = 0; i < MAX_CARDS; i++) {
		if ((monsterCards[i].name[0]) != '\0') {
			++counter;
		}
	}
	return counter;
}

void Deck::changeMagicCard(const MagicCard& r) {
	for (int i = 0; i < MAX_CARDS; i++) {
		if ((magicCards[i].name[0]) == '\0') {
			magicCards[i] = r;
			break;
		}
		if (i == 19) {
			cout << "There is not enough space in the deck!" << endl;
		}
	}
}

void Deck::changeMonsterCard(const MonsterCard& r) {
	for (int i = 0; i < MAX_CARDS; i++) {
		if ((monsterCards[i].name[0]) == '\0') {
			monsterCards[i] = r;
			break;
		}
		if (i == 19) {
			cout << "There is not enough space in the deck!" << endl;
		}
	}
}

void Deck::changeMagicCard(unsigned int index, const MagicCard& r) {
	magicCards[index] = r;
}

void Deck::changeMonsterCard(unsigned int index, const MonsterCard& r) {
	monsterCards[index] = r;
}
