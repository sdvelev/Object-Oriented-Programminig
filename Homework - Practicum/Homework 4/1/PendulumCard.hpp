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
#include"MonsterCard.hpp"
#include"MagicCard.hpp"

using namespace std;

class PendulumCard :public MonsterCard, public MagicCard {
private:
	double pendulumScale;
public:
	PendulumCard();
	PendulumCard(string _name, string _effect, unsigned int _rarity, unsigned int _attackPoints,
		unsigned int _deffencePoints, double _pendulumScale, CardType _cardType);

	double getPendulumScale() const;

	void setPendulumScale(double _pendulumScale);


	void print() const;

	Card* clone() const;

	friend ostream& operator<<(ostream& out, const PendulumCard& rhs);
};