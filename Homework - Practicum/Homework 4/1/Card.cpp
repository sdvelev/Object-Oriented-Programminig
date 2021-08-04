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
#include"Card.hpp"

using namespace std;

Card::Card() {
	this->name = "";
	this->effect = "";
	this->rarity = 0;
}

Card::Card(string _name, string _effect, unsigned int _rarity) {
	this->name = _name;
	this->effect = _effect;
	this->rarity = _rarity;
}

string Card::getName() const {
	return this->name;
}

string Card::getEffect() const {
	return this->effect;
}

unsigned int Card::getRarity() const {
	return this->rarity;
}

void Card::setName(string _name) {
	this->name = _name;
}

void Card::setEffect(string _effect) {
	this->effect = _effect;
}

void Card::setRarity(unsigned int _rarity) {
	this->rarity = _rarity;
}

bool Card::operator<(const Card& rhs) const{
	if (this->rarity < rhs.rarity) {
		return true;
	}
	else {
		return false;
	}
}

bool Card::operator>(const Card& rhs) const {
	return rhs < *this;
}
