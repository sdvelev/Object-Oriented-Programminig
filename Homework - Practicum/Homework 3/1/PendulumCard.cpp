/**
* Solution to homework assignment 3
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

PendulumCard::PendulumCard(string _name, string _effect, unsigned int _attackPoints, unsigned int _deffencePoints,
	CardType _cardType, double _pendulumScale) : Card(_name, _effect), MonsterCard(_name, _effect, _attackPoints,
		_deffencePoints), MagicCard(_name, _effect, _cardType) {
	if(_pendulumScale >= 1 && _pendulumScale <= 13){
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
	MonsterCard::print();
	cout << "Card Type: " << this->getCardTypeInString() << endl;
	cout << "Pendulum Scale: " << this->pendulumScale << endl;
}