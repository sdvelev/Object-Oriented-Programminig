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
#include "MagicCard.hpp"

using namespace std;

int m_strlen(const char str[]) {
	int counter = 0;
	while (str[counter++] != '\0');
	--counter;
	return counter;
}

MagicCard::MagicCard() {
	for (int i = 0; i < MAX_NAME; i++) {
		name[i] = '\0';
	}

	for (int i = 0; i < MAX_EFFECT; i++) {
		effect[i] = '\0';
	}

	type = trap;
}

MagicCard::MagicCard(const char* _name, const char* _effect, const Type& _type) {

	int length1 = m_strlen(_name);;

	for (int i = 0; i < length1; i++) {
		name[i] = _name[i];
	}
	name[length1] = '\0';


	int length2 = m_strlen(_effect);

	for (int i = 0; i < length2; i++) {
		effect[i] = _effect[i];
	}
	effect[length2] = '\0';

	type = _type;
}

void MagicCard::printName() const {
	int size = m_strlen(this->name);
	for (int i = 0; i < size; i++) {
		cout << name[i];
	}
	cout << endl;
}
