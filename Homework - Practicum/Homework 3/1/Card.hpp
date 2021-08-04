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

using namespace std;

class Card {
private:
	string name;
	string effect;
public:
	Card();
	Card(string _name, string _effect);

	string getName() const;
	string getEffect() const;

	void setName(string _name);
	void setEffect(string _effect);

	void print() const;
};