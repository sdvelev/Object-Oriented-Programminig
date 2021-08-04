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
#include"Materials.hpp"

using namespace std;

Materials::Materials() {
	this->materialsType = materialsTypeEnum::none;
	this->quantityHerbs = 0;
	this->quantityEssence = 0;
	this->quantityCloth = 0;
	this->quantityOres = 0;
	this->slots = 0;
}

int Materials::getQuantityHerbs() const{
	return this->quantityHerbs;
}

int Materials::getQuantityOres() const {
	return this->quantityOres;
}

int Materials::getQuantityCloth() const {
	return this->quantityCloth;
}

int Materials::getQuantityEssence() const {
	return this->quantityEssence;
}

int Materials::getSlots() const {
	return this->slots;
}

void Materials::setQuantityCloth(int _quantityCloth) {

	int calc = 0;
	if (_quantityCloth < 0 && _quantityCloth >-20) {
		calc = _quantityCloth / 20 - 1;
	}
	else if (_quantityCloth % 20 == 0) {
		calc = _quantityCloth / 20;
	}
	else {
		calc = _quantityCloth / 20 + 1;
	}

	if (((this->slots + calc) > 16 && _quantityCloth != 0) || _quantityCloth + this->getQuantityCloth() > 320) {
		cout << "You reached the maximum capacity of the Backpack!" << endl;
	}
	else {
		this->quantityCloth += _quantityCloth;
		this->materialsType = materialsTypeEnum::cloth;
		convertSlots();
	}
}

void Materials::setQuantityHerbs(int _quantityHerbs) {

	int calc = 0;
	if (_quantityHerbs < 0 && _quantityHerbs >-20) {
		calc = _quantityHerbs / 20 - 1;
	}
	else if (_quantityHerbs % 20 == 0) {
		calc = _quantityHerbs / 20;
	}
	else {
		calc = _quantityHerbs / 20 + 1;
	}

	if (((this->slots + calc) > 16 && _quantityHerbs != 0) || _quantityHerbs + this->getQuantityHerbs() > 320) {
		cout << "You reached the maximum capacity of the Backpack!" << endl;
	}
	else {
		this->quantityHerbs += _quantityHerbs;
		this->materialsType = materialsTypeEnum::herbs;
		convertSlots();
	}
}

void Materials::setQuantityOres(int _quantityOres) {
	int calc = 0;
	if (_quantityOres < 0 && _quantityOres >-20) {
		calc = _quantityOres / 20 - 1;
	}
	else if (_quantityOres % 20 == 0) {
		calc = _quantityOres / 20;
	}
	else {
		calc = _quantityOres / 20 + 1;
	}

	if (((this->slots + calc) > 16 && _quantityOres != 0) || _quantityOres + this->getQuantityOres() > 320) {
		cout << "You reached the maximum capacity of the Backpack!" << endl;
	}
	else {
		this->quantityOres += _quantityOres;
		this->materialsType = materialsTypeEnum::ores;
		convertSlots();
	}
}

void Materials::setQuantityEssence(int _quantityEssence) {

	int calc = 0;
	if (_quantityEssence < 0 && _quantityEssence >-20) {
		calc = _quantityEssence / 10 - 1;
	}
	else if (_quantityEssence % 10 == 0) {
		calc = _quantityEssence / 10;
	}
	else {
		calc = _quantityEssence / 10 + 1;
	}

	if (((this->slots + calc) > 16 && _quantityEssence != 0 )|| _quantityEssence + this->getQuantityEssence() > 160) {
		cout << "You reached the maximum capacity of the Backpack!" << endl;
	}
	else {
		this->quantityEssence += _quantityEssence;
		this->materialsType = materialsTypeEnum::essence;
		convertSlots();
	}
}

void Materials::convertSlots() {
		this->slots = 0;
		if (getQuantityEssence() == 0) {

		}
		else if (getQuantityEssence() <= 10) {
			this->slots = 1;
		}
		else if (getQuantityEssence() % 10 == 0) {
			this->slots = getQuantityEssence() / 10;
		}
		else {
			this->slots = getQuantityEssence() / 10 + 1;
		}

		if (getQuantityHerbs() == 0) {

		}
		else if (getQuantityHerbs() <= 20) {
			this->slots = this->slots + 1;
		}
		else if (getQuantityHerbs() % 20 == 0) {
			this->slots = this->slots + getQuantityHerbs() / 20;
		}
		else {
			this->slots = this->slots + getQuantityHerbs() / 20 + 1;
		}
	
		if (getQuantityOres() == 0) {
			
		}
		else if (getQuantityOres() <= 20) {
			this->slots = this->slots + 1;
		}
		else if (getQuantityOres() % 20 == 0) {
			this->slots = this->slots + getQuantityOres() / 20;
		}
		else {
			this->slots = this->slots + getQuantityOres() / 20 + 1;
		}

		if (getQuantityCloth() == 0) {
			
		}
		else if (getQuantityCloth() <= 20) {
			this->slots = this->slots + 1;
		}
		else if (getQuantityCloth() % 20 == 0) {
			this->slots =this->slots + getQuantityCloth() / 20;
		}
		else {
			this->slots =this->slots + getQuantityCloth() / 20 + 1;
		}
}

void Materials::emptyMaterials() {
	this->quantityCloth = 0;
	this->quantityEssence = 0;
	this->quantityHerbs = 0;
	this->quantityOres = 0;
	this->slots = 0;

}

void Materials::print() const{
	cout << "Quantity Cloth: " << this->getQuantityCloth() << endl;
	cout << "Quantity Essence: " << this->getQuantityEssence() << endl;
	cout << "Quantity Herbs: " << this->getQuantityHerbs() << endl;
	cout << "Quantity Ores: " << this->getQuantityOres() << endl;
	cout << "Slots: " << this->getSlots() << endl;
}
