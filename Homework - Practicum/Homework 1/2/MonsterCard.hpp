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

#pragma once

const int MAX_NAME = 26;
const int MAX_EFFECT = 101;
const int MAX_CARDS = 20;

class MonsterCard {
public:
	char name[MAX_NAME];
	MonsterCard();
	MonsterCard(const char*, unsigned int, unsigned int);

	void printName() const;

private:
	unsigned int attackPoints;
	unsigned int defensePoints;
};
