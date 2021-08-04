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
#include "MonsterCard.hpp"

using namespace std;

MonsterCard::MonsterCard() :Card() {
	this->attackPoints = 0;
	this->defencePoints = 0;
}

MonsterCard::MonsterCard(string _name, string _effect, unsigned int _rarity, unsigned int _attackPoints,
	unsigned int _defencePoints)
	: Card(_name, _effect, _rarity) {
	this->attackPoints = _attackPoints;
	this->defencePoints = _defencePoints;
}

unsigned int MonsterCard::getAttackPoints() const {
	return this->attackPoints;
}

unsigned int MonsterCard::getDefencePoints() const {
	return this->defencePoints;
}

void MonsterCard::setAttackPoints(unsigned int _attackPoints) {
	this->attackPoints = _attackPoints;
}

void MonsterCard::setDefencePoints(unsigned int _defencePoints) {
	this->defencePoints = _defencePoints;
}

void MonsterCard::print() const {
	cout << "Card Name: " << this->name << endl;
	cout << "Card Effect: " << this->effect << endl;
	cout << "Card Rarity: " << this->rarity << endl;
	cout << "Attack Points: " << this->attackPoints << endl;
	cout << "Defence Points: " << this->defencePoints << endl;
}

Card* MonsterCard::clone() const
{
	return new MonsterCard(*this);
}

ostream& operator<<(ostream& out, const MonsterCard& rhs)
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
	toPublish += newLine;

	out << toPublish;

	return out;
}
