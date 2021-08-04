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
#include"Armor.hpp"

using namespace std;

Armor::Armor() {
	this->type = ArmorType::none;
	this->defence = 0;
}

ArmorType Armor::getType() const {
	return this->type;
}

int Armor::getDefence() const {
	return this->defence;
}

vector<pair<string, double>> Armor::getEffect() const {
	return this->effect;
}

double Armor::getGearscore() const {
	double result = 0;
	if (this->effect.empty()) {
		return 0;
	}
	for (int i = 0; i < this->effect.capacity(); i++) {
		result += effect[i].second;
	}
	return result;
}

void Armor::setType(ArmorType _type) {
	this->type = _type;
}

void Armor::setDefence(int _deffence) {
	this->defence = _deffence;
}

void Armor::addEffect(string effectText, double effectPower) {
	
	if (effectPower < 0) {
		return;
	}
	
	for (int i = 0; i < this->effect.size(); i++) {
		if (effectText == this->effect[i].first) {
			this->effect[i].second = effectPower;
			return;
		}
	}

	if(effectPower >= 0){
		pair<string, double> newPair;
		newPair.first = effectText;
		newPair.second = effectPower;
		this->effect.push_back(newPair);
	}
}

void Armor::removeEffect(string effectText) {
	for (int i = 0; i < this->effect.size(); i++) {
		if (effectText == this->effect[i].first) {
			this->effect.erase(this->effect.begin() + i);
			break;
		}
	}
}

void Armor::setEffectPower(string effectName, double effectPower) {
	this->addEffect(effectName, effectPower);
}

bool operator==(const Armor& first, const Armor& second) {
	if (first.getGearscore() == second.getGearscore()) {
		return true;
	}
	return false;
}