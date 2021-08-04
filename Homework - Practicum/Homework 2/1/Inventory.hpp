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

using namespace std;

template <typename T>
class Inventory {
private:
	T item;
public:
	 friend bool operator==(const Inventory<T>& lhs, const Inventory<T>& rhs) {
		if (lhs.getSlots() == rhs.getSlots()) {
			return true;
		}
		return false;
	}


	 friend bool operator!=(const Inventory<T>& lhs, const Inventory<T>& rhs) {
		if (lhs.getSlots() != rhs.getSlots()) {
			return true;
		}
		return false;
	}

	 friend ostream& operator<<(ostream& out, const Inventory<T>& rhs) {
		rhs.print();
		return out;
	}

	 void print() const {
		 this->item.print();
	 }

	 int getSlots() const {
		 return this->item.getSlots();
	 }

	 void setInventory(const T& toReplace) {
		 this->item.set(toReplace);
	 }

};

