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

enum class CardType {
	TRAP,
	BUFF,
	SPELL,
	NONE
};

class MagicCard : virtual public Card {
protected:
	CardType cardType;
	
public:
	MagicCard();
	MagicCard(string _name, string _effect, unsigned int _rarity, CardType _cardType);

	CardType getCardType() const;
	string getCardTypeInString() const;

	void setCardType(CardType _cardType);

	void print() const;

	Card* clone() const;

	friend ostream& operator<<(ostream& out, const MagicCard& rhs);
};