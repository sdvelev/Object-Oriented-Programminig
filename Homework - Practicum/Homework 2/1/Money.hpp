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

#pragma once
#include<iostream>

class Money {
private:
	double money;

public:
	Money();

	void setSilver(int silver);
	void setGold(int gold);

	double getMoney() const;

	void eraseMoney();
	void print() const;
};