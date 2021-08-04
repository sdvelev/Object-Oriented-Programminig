#include "TestSuite.hpp"

TestSuite::TestSuite() {
	this->name = '\0';
}

TestSuite::TestSuite(std::string name) {
	this->name = name;
}

void TestSuite::add(const TestCase& new_testcase) {
	this->testcases.push_back(new_testcase);
}

std::string TestSuite::getName() const {
	return this->name;
}

void TestSuite::setName(const std::string& new_name) {
	this->name = new_name;
}

std::vector<TestCase> TestSuite::filterPassing() const {
	vector<TestCase> result;
	for (int i = 0; i < this->testcases.capacity(); i++) {
		if (this->testcases.at(i).isPassing()) {
			result.push_back(this->testcases.at(i));
		}
	}
	return result;
}

std::vector<TestCase> TestSuite::filterFailing() const {
	vector<TestCase> result;
	for (int i = 0; i < this->testcases.capacity(); i++) {
		if (this->testcases.at(i).isPassing() == false) {
			result.push_back(this->testcases.at(i));
		}
	}
	return result;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType error_type) const {
	vector<TestCase> result;
	for (int i = 0; i < this->testcases.capacity(); i++) {
		if (this->testcases.at(i).getErrorType() == error_type) {
			result.push_back(this->testcases.at(i));
		}
	}
	return result;
}

void TestSuite::removeByErrorType(ErrorType error_type) {
	for (int i = 0; i < this->testcases.size();) {
		if (this->testcases.at(i).getErrorType() == error_type) {
			this->testcases.erase(this->testcases.begin() + i);
			i = 0;
		}
		else {
			i++;
		}
	}
}