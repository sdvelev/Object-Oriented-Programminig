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

#pragma once

#include<iostream>
#include<string>
#include"Card.hpp"

using namespace std;

class MonsterCard : virtual public Card {
protected:
	unsigned int attackPoints;
	unsigned int defencePoints;
	
public:
	MonsterCard();
	MonsterCard(string _name, string _effect, unsigned int _rarity, unsigned int _attackPoints, unsigned int _defencePoints);

	unsigned int getAttackPoints() const;
	unsigned int getDefencePoints() const;

	void setAttackPoints(unsigned int _attackPonits);
	void setDefencePoints(unsigned int _defencePoints);

	void print() const;

	Card* clone() const;

	friend ostream& operator<<(ostream& out, const MonsterCard& rhs);
};