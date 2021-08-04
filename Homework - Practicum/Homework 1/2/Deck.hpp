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
#include "MagicCard.hpp"

class Deck {
public:
	MonsterCard monsterCards[MAX_CARDS];
	MagicCard magicCards[MAX_CARDS];

	unsigned int getMagicCardCount() const;
	unsigned int getMonsterCardCount() const;

	void changeMagicCard(const MagicCard&);
	void changeMonsterCard(const MonsterCard&);

	void changeMagicCard(unsigned int, const MagicCard&);
	void changeMonsterCard(unsigned int, const MonsterCard&);
};