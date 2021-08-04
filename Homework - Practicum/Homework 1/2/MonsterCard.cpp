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
#include "MonsterCard.hpp"

using namespace std;

int my_strlen(const char str[]) {
	int counter = 0;
	while (str[counter++] != '\0');
	--counter;
	return counter;
}

MonsterCard::MonsterCard (){
	for (int i = 0; i < MAX_NAME; i++) {
		name[i] = '\0';
	}
	attackPoints = 0;
	defensePoints = 0;
}

MonsterCard::MonsterCard(const char * _name, unsigned int _attackPoints, unsigned int _defensePoints) {
	
	int length = my_strlen(_name);
	
	for (int i = 0; i < length; i++) {
		name[i] = _name[i];
	}
	name[length] = '\0';
	attackPoints = _attackPoints;
	defensePoints = _defensePoints;
}

void MonsterCard::printName() const {
	int size = my_strlen(this->name);
	for (int i = 0; i < size; i++) {
		cout << name[i];
	}
	cout << endl;
}
