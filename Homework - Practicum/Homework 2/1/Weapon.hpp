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

enum class WeaponType {
	oneHanded,
	twoHanded,
	noneW
};

class Weapon {
private:
	WeaponType type;
	string weapon;
	pair<double, double> hitDamage;
	vector<pair<string, double>> effect;
public:
	Weapon();

	WeaponType getType() const;
	string getName() const;
	pair<double, double> getHitDamage() const;
	double getAverageHitDamage() const;
	vector<pair<string, double>> getEffect() const;
	double getWeaponScore() const;

	void setName(string _name);
	void setName(string _name, WeaponType _type);
	void setType(WeaponType _type);
	void addEffect(string effectName, double effectPower);
	void removeEffect(string effectName);
	void setEffectPower(int index, double _effectPower);
	void setEffectPower(string effectName, double effectPower);

	void setHitDamage(double minumum, double maximum);
	void setHitDamageMinimum(double minimum);
	void setHitDamageMaximum(double maximum);

	void print() const;

	friend bool operator==(const Weapon& first, const Weapon& second);
};