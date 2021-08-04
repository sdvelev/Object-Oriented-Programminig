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
#include "MagicCard.hpp"

using namespace std;

MagicCard::MagicCard() :Card() {
	this->cardType = CardType::NONE;
}

MagicCard::MagicCard(string _name, string _effect, CardType _cardType) : Card(_name, _effect) {
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
	Card::print();
	cout << "Card Type: " << this->getCardTypeInString() << endl;
}

