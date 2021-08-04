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
#include<vector>
#include"Armor.hpp"
#include"Weapon.hpp"


using namespace std;

template <typename T>
class Equipment {
private:
	vector<T> array;
	int slots;
public:
	bool isEmpty() const {
		return 0;
	}
	bool isFull() const {
		return 0;
	}
	void emptyEquipment() {
		return 0;
	}
	void addInEquipment() {
		return 0;
	}
	void removeInEquipment() {
		return 0;
	}
	T getBestEquipment() const {
		return 0;
	}

	friend bool operator!=(T first, T second) {
		return 0;
	}
	
};

template<>
class Equipment <Armor> {
private:
	vector<Armor> array;
	int slots;
public:
	int getSlots() const{
		int result = 0;
		if (this->array.empty()) {
			return result;
		}
		else {
			for (int i = 0; i < this->array.size(); i++) {

				if (this->array[i].getType() != ArmorType::none) {
					++result;
				}
			}
			return result;
		}
	}

	bool isFull() {
		int a = getSlots();
		return a == 24;
	}
	bool isEmpty() {
		int a = getSlots();
		return a == 0;
	}
	void emptyBackpack() {
		this->array.clear();
	}
	void addInEquipment(const Armor& to_add) {
		int a = getSlots();
		if (a == 24) {
			cout << "There is not enough space in Equipment!" << endl;
		}
		else {
			this->array.push_back(to_add);
		}
	}
	void removeInEquipment(int index) {
		this->array.erase(array.begin() + index);
	}

	double getGearscore() const{
		double sum = 0;
		for (int i = 0; i < this->array.size(); i++) {
			sum += this->array[i].getGearscore();
		}
		return sum;
	}

	friend bool operator==(const Equipment<Armor>& first, const Equipment<Armor>& second) {
		if (first.getGearscore() == second.getGearscore()) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Equipment<Armor>& first, const Equipment<Armor>& second) {
		if (first.getGearscore() != second.getGearscore()) {
			return true;
		}
		return false;
	}

	Armor getBestEquipment() const{
		
		if (this->array.empty()) {
			return Armor();
		}
		
		int index = 0;
		int max = -1;

		if (this->array.empty()) {
			return Armor();
		}
		for (int i = 0; i < this->array.capacity(); i++) {
			if (max < this->array[i].getGearscore()) {
				max = this->array[i].getGearscore();
			}
		}

		for (int i = 0; i < this->array.capacity(); i++) {
			if (max == this->array[i].getGearscore()) {
				index = i;
				break;
			}
		}
		return this->array[index];
	}

	void print()const {

		if (this->array.size() == 0) {
			cout << "There is no Armor!" << endl;
		}

		for (int i = 0; i < this->array.size(); i++) {
			
			if (this->array[i].getType() == ArmorType::cloth) {
				cout << "Armor Type: cloth" << endl;
			}
			else if (this->array[i].getType() == ArmorType::leather) {
				cout << "Armor Type: leather" << endl;
			}
			else if (this->array[i].getType() == ArmorType::mail) {
				cout << "Armor Type: mail" << endl;
			}
			else {
				cout << "Armor Type: none" << endl;
			}

			cout << "Armor Deffence: " << this->array[i].getDefence() << endl;

			for (int j = 0; j < this->array[i].getEffect().size(); j++) {
				cout << "Effect Name: " << this->array[i].getEffect()[j].first << endl;
				cout << "Effect Power: " << this->array[i].getEffect()[j].second << endl;
			}

			cout << "Gear Score: " << this->array[i].getGearscore() << endl;
			cout << endl;
		}		
	}
	void set(const Equipment<Armor>& toReplace) {
		this->array = toReplace.array;
		this->slots = toReplace.slots;
	}
};


template<>
class Equipment<Weapon> {
private:
	vector<Weapon> array;
	int slots;
public:


	int getSlots() const{
		int result = 0;
		if (this->array.empty()) {
			return result;
		}
		else {
			for (int i = 0; i < this->array.size(); i++) {
				if (array[i].getType() == WeaponType::oneHanded) {
					++result;
				}
				else if (array[i].getType() == WeaponType::twoHanded) {
					result = result + 2;
				}
			}
			return result;
		}
	}

	bool isFull() {
		int a = getSlots();
		return a == 24;
	}
	bool isEmpty() {
		int a = getSlots();
		return a == 0;
	}
	void emptyBackpack() {
		this->array.clear();
	}
	void addInEquipment(const Weapon& to_add) {
		int a = getSlots();
		if (a == 24) {
			cout << "There is not enough space in Equipment!" << endl;
		}
		else {
			this->array.push_back(to_add);
		}
	}
	void removeInEquipment(int index) {
		this->array.erase(array.begin() + index);
	}

	void removeInEquipment(string name) {
		for (int i = 0; i < this->array.size(); i++) {
			if (this->array[i].getName() == name) {
				this->array.erase(array.begin() + i);
				return;
			}
		}
	}

	friend bool operator==(const Equipment<Weapon>& first, const Equipment<Weapon>& second) {
		if (first.getWeaponScore() == second.getWeaponScore()) {
			return true;
		}
		return false;
	}

	friend bool operator!=(const Equipment<Weapon>& first, const Equipment<Weapon>& second) {
		if (first.getWeaponScore() != second.getWeaponScore()) {
			return true;
		}
		return false;
	}

	double getWeaponScore() const {
		double sum = 0;
		for (int i = 0; i < this->array.size(); i++) {
			sum += this->array[i].getWeaponScore();
		}
		return sum;
	}

	Weapon getBestEquipment() const{
		
		if (this->array.empty()) {
			return Weapon();
		}
		
		int index = 0;
		int max = -1;

		for (int i = 0; i < this->array.capacity(); i++) {
			if (max < this->array[i].getWeaponScore()) {
				max = this->array[i].getWeaponScore();
			}
		}

		for (int i = 0; i < this->array.capacity(); i++) {
			if (max == this->array[i].getWeaponScore()) {
				index = i;
				break;
			}
		}
		return this->array[index];
	}

	void print()const {

		if (this->array.size() == 0) {
			cout << "There is no Weapon!" << endl;
		}

		for (int i = 0; i < this->array.size(); i++) {

			if (this->array[i].getType() == WeaponType::oneHanded) {
				cout << "Weapon Type: one-handed" << endl;
			}
			else if (this->array[i].getType() == WeaponType::twoHanded) {
				cout << "Weapon Type: two-handed" << endl;
			}

			cout << "Weapon Kind: " << this->array[i].getName() << endl;

			cout << "Hit damage - Minimum: " << this->array[i].getHitDamage().first << endl;
			cout << "Hit damage - Maximum: " << this->array[i].getHitDamage().second << endl;

			for (int j = 0; j < this->array[i].getEffect().size(); j++) {
				cout << "Effect Name: " << this->array[i].getEffect()[j].first << endl;
				cout << "Effect Power: " << this->array[i].getEffect()[j].second << endl;
			}

			cout << "Weapon Score: " << this->array[i].getWeaponScore() << endl;
			cout << endl;
		}
	}
	void set(const Equipment<Weapon>& toReplace) {
		this->array = toReplace.array;
		this->slots = toReplace.slots;
	}
};
