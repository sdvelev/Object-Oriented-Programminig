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
#include "MagicCard.hpp"

using namespace std;


MagicCard::MagicCard() :Card() {
	this->cardType = CardType::NONE;
}

MagicCard::MagicCard(string _name, string _effect, unsigned int _rarity, CardType _cardType)
	: Card(_name, _effect, _rarity) {
	if (this->cardType != CardType::NONE) {
		this->cardType = _cardType;
	}
}

CardType MagicCard::getCardType() const {
	return this->cardType;
}

string MagicCard::getCardTypeInString() const {
	if (this->cardType == CardType::BUFF) {
		return "BUFF";
	}
	if (this->cardType == CardType::SPELL) {
		return "SPELL";
	}
	if (this->cardType == CardType::TRAP) {
		return "TRAP";
	}
	if (this->cardType == CardType::NONE) {
		return "";
	}
}

void MagicCard::setCardType(CardType _cardType) {
	if (_cardType != CardType::NONE) {
		this->cardType = _cardType;
	}
}

void MagicCard::print() const {
	cout << "Card Name: " << this->name << endl;
	cout << "Card Effect: " << this->effect << endl;
	cout << "Card Rarity: " << this->rarity << endl;
	cout << "Card Type: " << this->getCardTypeInString() << endl;
}

Card* MagicCard::clone() const
{
	return new MagicCard(*this);
}

ostream& operator<<(ostream& out, const MagicCard& rhs)
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
	toPublish += rhs.getCardTypeInString();
	toPublish += newLine;

	out << toPublish;

	return out;
}
