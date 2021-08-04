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

#include<iostream>
#include<string>
#include "PendulumCard.hpp"

using namespace std;

PendulumCard::PendulumCard() :Card(), MonsterCard(), MagicCard() {
	this->pendulumScale = 1;
}

PendulumCard::PendulumCard(string _name, string _effect, unsigned int _rarity, unsigned int _attackPoints,
	unsigned int _deffencePoints, double _pendulumScale, CardType _cardType) : Card(_name, _effect, _rarity),
	MonsterCard(_name, _effect, _rarity, _attackPoints, _deffencePoints), MagicCard(_name, _effect, _rarity, _cardType) {
	if (_pendulumScale >= 1 && _pendulumScale <= 13) {
		this->pendulumScale = _pendulumScale;
	}
	else {
		this->pendulumScale = 0;
	}
}


double PendulumCard::getPendulumScale() const {
	return this->pendulumScale;
}

void PendulumCard::setPendulumScale(double _pendulumScale) {
	if (_pendulumScale >= 1 && _pendulumScale <= 13) {
		this->pendulumScale = _pendulumScale;
	}
}

void PendulumCard::print() const {
	cout << "Card Name: " << this->name << endl;
	cout << "Card Effect: " << this->effect << endl;
	cout << "Card Rarity: " << this->rarity << endl;
	cout << "Attack Points: " << this->attackPoints << endl;
	cout << "Defence Points: " << this->defencePoints << endl;
	cout << "Card Type: " << this->getCardTypeInString() << endl;
	cout << "Pendulum Scale: " << this->pendulumScale << endl;
}

Card* PendulumCard::clone() const
{
	return new PendulumCard(*this);
}

ostream& operator<<(ostream& out, const PendulumCard& rhs)
{
	char divider = '|';
	char newLine = '\n';

	string toPublish;

	toPublish += rhs.getName();
	toPublish += divider;
	toPublish += rhs.getEffect();
	toPublish += divider;
	toPublish += to_string(rhs.getRarity());
	toPublish += divider;
	toPublish += to_string(rhs.getAttackPoints());
	toPublish += divider;
	toPublish += to_string(rhs.getDefencePoints());
	toPublish += divider;
	toPublish += to_string(rhs.getPendulumScale());
	toPublish += divider;
	toPublish += rhs.getCardTypeInString();
	toPublish += newLine;

	out << toPublish;

	return out;
}
