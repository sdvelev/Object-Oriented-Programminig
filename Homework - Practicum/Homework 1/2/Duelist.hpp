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
#include "Deck.hpp"
#include "MonsterCard.hpp"
#include "MagicCard.hpp"


class Duelist {
public:


	Duelist(const char* _name = "default");
	Duelist(const char*, const Deck&);
	~Duelist();

	Duelist(const Duelist&);
	Duelist& operator=(const Duelist&);

	void printName() const;

	void setName(const char*);
	void setDeck(const Deck&);

	unsigned int getMagicCardCount() const;
	unsigned int getMonsterCardCount() const;

	void changeMagicCardInDeck(const MagicCard&);
	void changeMonsterCardInDeck(const MonsterCard&);

	void changeMagicCardInDeck(unsigned int, const MagicCard&);
	void changeMonsterCardInDeck(unsigned int, const MonsterCard&);

private:
	char* name;
	Deck deck;
};