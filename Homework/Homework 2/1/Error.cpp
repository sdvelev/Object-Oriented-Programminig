#include<iostream>
#include<string>
#include"Error.hpp"


Error::Error(const std::string& message) {
	this->message = message;
	this->error = true;
}

std::string Error::get_message() const {
	return this->message;
}

