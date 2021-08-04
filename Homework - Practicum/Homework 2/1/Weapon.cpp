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
#include<utility>
#include"Weapon.hpp"

using namespace std;

Weapon::Weapon() {
	this->type = WeaponType::noneW;
	this->weapon = "";
	this->hitDamage.first = 0;
	this->hitDamage.second = 0;
}

WeaponType Weapon::getType() const{
	return this->type;
}

string Weapon::getName() const {
	return this->weapon;
}

pair<double, double> Weapon::getHitDamage() const {
	return this->hitDamage;
}

double Weapon::getAverageHitDamage() const {
	double minimum = this->hitDamage.first;
	double maximum = this->hitDamage.second;
	double average = (minimum + maximum) / 2;
	return average;
}

vector<pair<string, double>> Weapon::getEffect() const {
	return this->effect;
}

double Weapon::getWeaponScore() const {
	double result = 0;
	double sumOfEffects = 0;
	for (int i = 0; i < this->effect.size(); i++) {
		sumOfEffects += effect[i].second;
	}
	
	result = sumOfEffects + this->getAverageHitDamage();
	if (this->getType() == WeaponType::oneHanded) {
		result = result * 0.75;
	}
	else if (this->getType() == WeaponType::twoHanded) {
		result = result * 1.5;
	}
	return result;
}

void Weapon::setName(string _name) {
	if (_name == "staff" && this->type == WeaponType::oneHanded) {
		cout << "Staff can be only two-handed!" << endl;
		return;
	}

	if (_name == "dagger" && this->type == WeaponType::twoHanded) {
		cout << "Dagger can be only one-handed!" << endl;
		return;
	}
	this->weapon = _name;
}


void Weapon::setName(string _name, WeaponType _type) {
	
	if (_name == "staff" && _type == WeaponType::oneHanded) {
		cout << "Staff can be only two-handed!" << endl;
		return;
	}

	if (_name == "dagger" && _type == WeaponType::twoHanded) {
		cout << "Dagger can be only one-handed!" << endl;
		return;
	}
	
	this->weapon = _name;
	this->type = _type;
}

void Weapon::setType(WeaponType _type) {

	if (this->weapon == "staff" && _type == WeaponType::oneHanded) {
		cout << "Staff can be only two-handed!" << endl;
		return;
	}

	if (this->weapon == "dagger" && _type == WeaponType::twoHanded) {
		cout << "Dagger can be only one-handed!" << endl;
		return;
	}

	this->type = _type;
}

void Weapon::addEffect(string effectName, double effectPower) {
	
	if (effectPower < 0) {
		return;
	}

	for (int i = 0; i < this->effect.size(); i++) {
		if (effectName == this->effect[i].first) {
			this->effect[i].second = effectPower;
			return;
		}
	}

	pair<string, double> newPair;
	newPair.first = effectName;
	newPair.second = effectPower;
	this->effect.push_back(newPair);
	
}

void Weapon::removeEffect(string effectName) {
	for (int i = 0; i < this->effect.size(); i++) {
		if (effectName == this->effect[i].first) {
			this->effect.erase(this->effect.begin() + i);
			break;
		}
	}
}

void Weapon::setEffectPower(int index, double _effectPower) {
	this->effect[index].second = _effectPower;
}

void Weapon::setEffectPower(string effectName, double effectPower) {
	this->addEffect(effectName, effectPower);
}


bool operator==(const Weapon& first, const Weapon& second) {
	if (first.getWeaponScore() == second.getWeaponScore()) {
		return true;
	}
	return false;
}

void Weapon::print() const {

	if (this->getType() == WeaponType::oneHanded) {
		cout << "Weapon Type: one-handed" << endl;
	}
	else if (this->getType() == WeaponType::twoHanded) {
		cout << "Weapon Type: two-handed" << endl;
	}
	else {
		cout << "Weapon Type: none" << endl;
	}

	if (this->getName() == "") {
		cout << "Weapon Kind: none"<< endl;
	}
	else {
		cout << "Weapon Kind: " << this->getName() << endl;
	}

	cout << "Hit damage - Minimum: " << this->getHitDamage().first << endl;
	cout << "Hit damage - Maximum: " << this->getHitDamage().second << endl;

	if (this->getEffect().size() == 0) {
		cout << "Effect Name: none" << endl;
		cout << "Effect Power: none" << endl;
	}
	else {
		for (int j = 0; j < this->getEffect().size(); j++) {
			cout << "Effect Name: " << this->getEffect()[j].first << endl;
			cout << "Effect Power: " << this->getEffect()[j].second << endl;
		}
	}
	
	cout << "Weapon Score: " << this->getWeaponScore() << endl;
}

void Weapon::setHitDamage(double minimum, double maximum) {
	this->hitDamage.first = minimum;
	this->hitDamage.second = maximum;
}

void Weapon::setHitDamageMinimum(double minimum) {
	this->hitDamage.first = minimum;
}

void Weapon::setHitDamageMaximum(double maximum) {
	this->hitDamage.second = maximum;
}