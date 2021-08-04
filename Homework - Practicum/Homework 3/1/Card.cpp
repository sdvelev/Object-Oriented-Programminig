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
#include"Card.hpp"

using namespace std;

Card::Card() {
	this->name = "";
	this->effect = "";
}

Card::Card(string _name, string _effect) {
	this->name = _name;
	this->effect = _effect;
}

string Card::getName() const {
	return this->name;
}

string Card::getEffect() const {
	return this->effect;
}

void Card::setName(string _name) {
	this->name = _name;
}

void Card::setEffect(string _effect) {
	this->effect = _effect;
}

void Card::print() const {
	cout << "Card Name: " << this->name << endl;
	cout << "Card Effect: " << this->effect << endl;
}