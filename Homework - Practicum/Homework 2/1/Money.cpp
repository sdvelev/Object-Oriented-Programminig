/**
* Solution to homework assignment 2
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
#include"Money.hpp"

using namespace std;

Money::Money() {
	money = 0;
}

void Money::setSilver(int silver) {
	if (silver < 100) {
		this->money = this->money + ((double) silver / 100.0);
	}
	else {
		this->money = this->money + silver / 100 + ((silver % 100) / 100.0);
	}
}

void Money::setGold(int gold) {
	this->money = this->money + gold;
}

double Money::getMoney() const {
	return this->money;
}

void Money::eraseMoney() {
	this->money = 0;
}

void Money::print() const {
	int wholePart = (int)this->getMoney();
	double decimalPart = (this->getMoney() - wholePart) * 100;
	cout << "Gold: " << wholePart << endl;
	cout << "Silver: " << decimalPart << endl;
}