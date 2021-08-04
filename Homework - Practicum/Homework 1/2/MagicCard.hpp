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
#include "MonsterCard.hpp"

enum Type { trap, buff, spell };

class MagicCard {
public:
	char name[MAX_NAME];

	MagicCard();
	MagicCard(const char*, const char*, const Type&);

	void printName() const;
private:
	char effect[MAX_EFFECT];
	Type type;

};