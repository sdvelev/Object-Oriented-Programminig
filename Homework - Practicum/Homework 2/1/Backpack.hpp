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
#include"Materials.hpp"
#include"Money.hpp"


template <typename T>
class Backpack {
private:
	int slots;
public:
	bool isEmpty() {
		return 0;
	}
	bool isFull() {
		return 0;
	}
	void emptyBackpack() {
		return 0;
	}
	void addInBackpack() {
		return 0;
	}
	void removeInBackpack() {
		return 0;
	}
	int getSlots() const {
		return 0;
	}
};

template<>
class Backpack <Materials> {
private:
	Materials a;
public:
	bool isFull() {
		return a.getSlots() == 12;
	}
	bool isEmpty() {
		return a.getSlots() == 0;
	}
	void emptyBackpack() {
		a.emptyMaterials();
	}
	void addInBackpack(materialsTypeEnum type, unsigned int quantity) {
		if (type == materialsTypeEnum::cloth) {
			a.setQuantityCloth(quantity);
		}
		else if (type == materialsTypeEnum::essence) {
			a.setQuantityEssence(quantity);
		}
		else if (type == materialsTypeEnum::herbs) {
			a.setQuantityHerbs(quantity);
		}
		else if (type == materialsTypeEnum::ores) {
			a.setQuantityOres(quantity);
		}
	}
	void removeInBackpack(materialsTypeEnum type, int quantity) {
		if (type == materialsTypeEnum::cloth) {
			if (a.getQuantityCloth() < quantity) {
				cout << "You do not have enough materials in the Backpack!" << endl;
			}
			else {
				a.setQuantityCloth(-quantity);
			}
		}
		else if (type == materialsTypeEnum::essence) {
			if (a.getQuantityEssence() < quantity) {
				cout << "You do not have enough materials in the Backpack!" << endl;
			}
			else {
				a.setQuantityEssence(-quantity);
			}
		}
		else if (type == materialsTypeEnum::herbs) {
			if (a.getQuantityHerbs() < quantity) {
				cout << "You do not have enough materials in the Backpack!" << endl;
			}
			else {
				a.setQuantityHerbs(-quantity);
			}
		}
		else if (type == materialsTypeEnum::ores) {
			if (a.getQuantityOres() < quantity) {
				cout << "You do not have enough materials in the Backpack!" << endl;
			}
			else {
				a.setQuantityOres(-quantity);
			}
		}
	}

	void print() const {
		this->a.print();
	}
	int getSlots() const {
		return a.getSlots();
	}

	void set(const Backpack<Materials>& toReplace) {
		this->a = toReplace.a;
	}
};

enum moneyMean {
	silver,
	gold
};


template<>
class Backpack<Money> {
private:
	Money a;
public:
	bool isFull() {
		return false;
	}
	bool isEmpty() {
		return a.getMoney() == 0;
	}
	void emptyBackpack() {
		a.eraseMoney();
	}
	void addInBackpack(moneyMean mean, int quantity) {
		if (mean == moneyMean::silver) {
			a.setSilver(quantity);
		}
		else if (mean == moneyMean::gold) {
			a.setGold(quantity);
		}
	}

	void addInBackpack(moneyMean mean1, int quantity1, moneyMean mean2, int quantity2) {
		if (mean1 == moneyMean::silver) {
			a.setSilver(quantity1);
		}
		else if (mean1 == moneyMean::gold) {
			a.setGold(quantity1);
		}

		if (mean2 == moneyMean::silver) {
			a.setSilver(quantity2);
		}
		else if (mean2 == moneyMean::gold) {
			a.setGold(quantity2);
		}
	}

	void removeInBackpack(moneyMean mean, int quantity) {
		if (mean == moneyMean::silver) {
			int wholePart = (int)a.getMoney();
			double decimalPart = (a.getMoney() - wholePart) * 100;
			if ((wholePart * 100 + decimalPart) < quantity) {
				cout << "You do not have enough money in the Backpack!" << endl;
			}
			else {
				a.setSilver(-quantity);
			}
		}
		else if (mean == moneyMean::gold) {
			int wholePart = (int)a.getMoney();
			double decimalPart = (a.getMoney() - wholePart) * 100;
			if ((wholePart * 100 + decimalPart) < quantity * 100) {
				cout << "You do not have enough money in the Backpack!" << endl;
			}
			else {
				a.setGold(-quantity);
			}
		}
	}
	void print() const {
		this->a.print();
	}
	int getSlots() const {
		return a.getMoney();
	}
	void set(const Backpack<Money>& toReplace) {
		this->a = toReplace.a;
	}
};


