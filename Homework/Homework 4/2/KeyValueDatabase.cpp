#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"KeyValueDatabase.hpp"

using namespace std;

const char newline = '\n';

KeyValueDatabase::KeyValueDatabase() : Object()
{
}

KeyValueDatabase::KeyValueDatabase(const std::string& _name, const std::string& _location, const std::string& _extension)
	:Object(_name, _location, _extension)
{
}


void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
	for (int i = 0; i < this->data.size(); i++) {
		if (this->data[i].first == entry.first) {
			throw std::invalid_argument("The argument is invalid!");
		}
	}
	this->data.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const
{
	for (int i = 0; i < this->data.size(); i++) {
		if (this->data[i].first == key) {
			return this->data[i].second;
		}
	}
	throw std::invalid_argument("The argument is invalid!");
}

Object* KeyValueDatabase::clone() const
{
	return new KeyValueDatabase(*this);
}


bool KeyValueDatabase::operator==(const Comparable* rhs) const
{
	const KeyValueDatabase* keyValueDatabasePtr = dynamic_cast<const KeyValueDatabase*>(rhs);
	if (keyValueDatabasePtr) {
		if (this->data.size() == keyValueDatabasePtr->data.size()) {
			for (int i = 0; i < this->data.size(); i++) {
				if (this->data[i].first != keyValueDatabasePtr->data[i].first || 
					this->data[i].second != keyValueDatabasePtr->data[i].second) {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	return false;
}

bool KeyValueDatabase::operator!=(const Comparable* rhs) const
{
	const KeyValueDatabase* keyValueDatabasePtr = dynamic_cast<const KeyValueDatabase*>(rhs);
	if (*(this) == keyValueDatabasePtr) {
		return false;
	}
	else {
		return true;
	}
}

string KeyValueDatabase::to_string() const
{
	
	if (this->name == "" || this->location == "" || this->extension == "") {
		return "";
	}

	string result;
	result += this->name;
	result.push_back(newline);
	result += this->location;
	result.push_back(newline);
	result += this->extension;
	result.push_back(newline);
	for (int i = 0; i < this->data.size(); i++) {
		result += this->data[i].first;
		result += ":";
		result += std::to_string(this->data[i].second);
		result.push_back(newline);
	}
	return result;
}

void KeyValueDatabase::from_string(const string& other)
{
	
	if (other.empty()) {
		return;
	}

	size_t occurences = std::count(other.begin(), other.end(), newline);

	if (occurences < 3) {
		return;
	}

	unsigned int flag = 0;
	this->name.clear();
	this->location.clear();
	this->extension.clear();
	this->data.clear();

	for (int i = 0; other[i] != newline; i++) {
		this->name.push_back(other[i]);

		if (other[i + 1] == newline) {
			flag = i + 2;
		}
	}

	for (int j = flag; other[j] != newline; j++) {
		this->location.push_back(other[j]);

		if (other[j + 1] == newline) {
			flag = j + 2;
		}
	}

	for (int k = flag; other[k] != newline; k++) {
		this->extension.push_back(other[k]);

		if (other[k + 1] == newline) {
			flag = k + 2;
		}
	}

	string copied;

	pair <string, int> toPublish;

	char divider = ':';

	for (int l = flag; l < other.size(); l++) {
		if (other[l] != divider) {
			toPublish.first.push_back(other[l]);
		}
		else if (other[l] != newline) {
			++l;
			while (other[l] > '0' && other[l] < '9') {
				copied.push_back(other[l]);
				++l;
			}

			int number = stoi(copied);
			toPublish.second = number;
			this->add_entry(toPublish);
			copied.clear();
			toPublish.first.clear();
		}
	}
}

string KeyValueDatabase::debug_print() const
{
	string result;

	for (auto rows : this->data) {
		result += "{";
		result += rows.first;
		result += ":";
		result += std::to_string(rows.second);
		result += "}";
		result += newline;
	}
	return result;
}