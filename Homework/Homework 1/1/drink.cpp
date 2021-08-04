

#include"drink.hpp"


Drink::Drink() {
	this->name = new char[1];
	this->name[0] = '\0';
	this->calories = 0;
	this->quantity = 0.0;
	this->price = 0.0;
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price) {
	this->name = new char[strlen(init_name) + 1];
	strcpy(this->name, init_name);
	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->calories = other.calories;
	this->quantity = other.quantity;
	this->price = other.price;
}

Drink& Drink::operator=(const Drink& other) {
	if (this != &other) {
		delete[] this->name;
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->calories = other.calories;
		this->quantity = other.quantity;
		this->price = other.price;
	}
	return *this;
}

const char* Drink::get_name() const{
	return this->name;
}

int Drink::get_calories() const{
	return this->calories;
}

double Drink::get_quantity() const {
	return this->quantity;
}

double Drink::get_price() const {
	return this->price;
}


void Drink::set_name(const char* new_name) {
	delete[] this->name;
	if (new_name == nullptr) {
		this->name = new char[1];
		this->name[0] = '\0';
	}
	else {
		this->name = new char[strlen(new_name) + 1];
		strcpy(this->name, new_name);
	}
}

void Drink::set_calories(const int new_calories) {
	this->calories = new_calories;
}

void Drink::set_quantity(const double new_quantity) {
	this->quantity = new_quantity;
}

void Drink::set_price(const double new_price) {
	this->price = new_price;
}

Drink::~Drink() {
	delete[] name;
}