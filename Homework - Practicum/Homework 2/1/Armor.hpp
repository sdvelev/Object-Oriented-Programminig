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
#include<utility>
#include<vector>

using namespace std;


enum class ArmorType {
	cloth,
	leather,
	mail,
	none
};

class Armor {
private:
	ArmorType type;
	int defence;
	vector<pair<string, double>> effect;
public:
	Armor();

	ArmorType getType() const;
	int getDefence() const;
	vector<pair<string, double>> getEffect() const;
	double getGearscore() const;

	void setType(ArmorType _type);
	void setDefence(int deffence);
	void addEffect(string effectText, double effectPower);

	void setEffectPower(string effectName, double effectPower);

	void removeEffect(string effectText);
	friend bool operator==(const Armor& first, const Armor& second);
};

