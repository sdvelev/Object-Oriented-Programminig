#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error) {
	this->name = name;
	this->error = error;
}

std::string TestCase::getName() const {
	return this->name;
}

bool TestCase::isPassing() const {
	if (this->error.getType() == ErrorType::None || this->error.getType() == ErrorType::Warning) {
		return true;
	}
	else {
		return false;
	}
}

bool TestCase::hasError() const {
	if (this->error.getType() == ErrorType::None) {
		return false;
	}
	else {
		return true;
	}
}

ErrorType TestCase::getErrorType() const {
	return this->error.getType();
}

std::string TestCase::getErrorMessage() const {
	if (this->hasError()) {
		int length = strlen(this->error.getMessage());
		char* old_message = new char[length+1];
		strcpy(old_message, this->error.getMessage());
		string new_message;
		for (int i = 0; i < length; i++) {
			new_message += old_message[i];
		}
		delete[] old_message;
		return new_message;
	}
	else {
		return "";
	}
}