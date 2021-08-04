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
private:
	CardType cardType;
public:
	MagicCard();
	MagicCard(string _name, string _effect, CardType _cardType);

	CardType getCardType() const;
	string getCardTypeInString() const;

	void setCardType(CardType _cardType);

	void print() const;
};