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

using namespace std;

class Card {
protected:
	string name;
	string effect;
	unsigned int rarity;
public:
	Card();
	Card(string _name, string _effect, unsigned int _rarity);

	string getName() const;
	string getEffect() const;
	unsigned int getRarity() const;

	void setName(string _name);
	void setEffect(string _effect);
	void setRarity(unsigned int _rarity);

	virtual bool operator>(const Card& rhs) const;
	virtual bool operator<(const Card& rhs) const;

	virtual Card* clone() const = 0;

	virtual void print() const = 0;
	virtual ~Card() = default;
};