#include<iostream>
#include<string>
#include"Request.hpp"

using namespace std;

int Request::counter = 0;

Request::Request() {
	this->message = "";
	this->sender = "";
	this->counter = this->counter + 1;
	this->ID = this->counter;
}

Request::Request(const string& message, const string& sender) {
	this->message = message;
	this->sender = sender;
	this->counter = this->counter + 1;
	this->ID = this->counter;
}

string Request::getMessage() const {
	return this-> message;
}

string Request::getSender() const {
	return this->sender;
}

int Request::getCount() const {
	return this->counter;
}

int Request::getID() const {
	return this->ID;
}

void Request::setMessage(const string& message) {
	this->message = message;
}

void Request::setSender(const string& sender) {
	this->sender = sender;
}