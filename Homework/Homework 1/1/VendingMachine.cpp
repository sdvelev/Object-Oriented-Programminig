

#include "VendingMachine.hpp"

VendingMachine::VendingMachine() {
	this->income = 0.0;
}

VendingMachine::VendingMachine(const VendingMachine& from) {
	for (int i = 0; i < MAX_SIZE; i++) {
		this->drink[i] = from.drink[i];
	}
	this->income = from.income;
	if (counter == MAX_SIZE) {
		VendingMachineGrow();
	}
	else {
		++counter;
	}
}

void VendingMachine::VendingMachineGrow() {
	MAX_SIZE = MAX_SIZE * 2;
	Drink* drink2 = new Drink[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE / 2; i++) {
		drink2[i] = this->drink[i];
	}
	delete[] this->drink;
	this->drink = drink2;

}

VendingMachine& VendingMachine::operator=(const VendingMachine& from) {
	if (this != &from) {
		for (int i = 0; i < 100; i++) {
			this->drink[i] = from.drink[i];
		}
		this->income = from.income;
	}
	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; this->drink[i].get_name()[j] != '\0'; j++) {
			if (this->drink[i].get_name()[j] == to_add.get_name()[j]) {
				if (j == (strlen(to_add.get_name()) - 1)) {
					return false;
				}
			}
		}
	}

	if (counter == MAX_SIZE) {
		VendingMachineGrow();
	}
	++counter;

	for (int k = 0; k < MAX_SIZE; k++) {
		if (this->drink[k].get_name()[0] == '\0') {
			this->drink[k] = to_add;
			return true;
		}
	}
}

int VendingMachine::buy_drink(const char * drink_name, const double money) {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; this->drink[i].get_name()[j] != '\0'; j++) {
			if (this->drink[i].get_name()[j] == drink_name[j]) {
				if (j == (strlen(this->drink[i].get_name()) - 1)) {
					if (money >= this->drink[i].get_price()) {
						this->income = this->income + money;
						const char* empty = nullptr;
						this->drink[i].set_name(empty);
						this->drink[i].set_calories(0);
						this->drink[i].set_quantity(0.0);
						this->drink[i].set_price(0.0);
						--counter;
						return 0;
					}
					else {
						this->income = this->income + money;
						return 1;
					}
				}
			}
		}
	}
	return 2;
}

double VendingMachine::get_income() const {
	return this->income;
}

VendingMachine::~VendingMachine() {
	delete[] drink;
}