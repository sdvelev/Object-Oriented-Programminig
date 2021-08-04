#include<iostream>
#include<algorithm>
#include"Document.hpp"

const char newline = '\n';

Document::Document() : Object() {
	this->counter = 1;
}

Document::Document(const std::string& _name, const std::string& _location, const std::string& _extension)
	:Object(_name, _location, _extension)
{
	this->counter = 1;
}

Document::Document(const Document& other) : Object(other)
{
	this->counter = 1;
	this->data = other.data;
}

Document& Document::operator=(const Document& rhs)
{
	if (this != &rhs) {
		Object::operator=(rhs);
		this->counter = 1;
		this->data = rhs.data;
	}
	return *this;
}

void Document::write_line(const std::string& line)
{
	this->data.push_back(line);
}



Object* Document::clone() const
{
	return new Document(*this);
}

bool Document::operator==(const Comparable* rhs) const
{
	const Document* documentPtr = dynamic_cast<const Document*>(rhs);
	if (documentPtr) {
		if (this->data.size() == documentPtr->data.size()) {
			for (int i = 0; i < this->data.size(); i++) {
				if (this->data[i] != documentPtr->data[i]) {
					return false;
				}
			}
		}
		else {
			return false;
		}
		return true;
	}
	else {
		return false;
	}
}

bool Document::operator!=(const Comparable* rhs) const
{
	const Document* documentPtr = dynamic_cast<const Document*>(rhs);
	if (*(this) == documentPtr) {
		return false;
	}
	else {
		return true;
	}
}

string Document::to_string() const
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
		result += this->data[i];
		result.push_back(newline);
	}
	return result;
}

void Document::from_string(const string& other)
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

	for (int l = flag; l < other.size(); l++) {
		if (other[l] != newline) {
			copied.push_back(other[l]);
		}
		else {
			this->data.push_back(copied);
			copied.clear();
		}
	}
}

string Document::debug_print() const
{
	string result;

	unsigned int number = 1;
	for (auto rows : this->data) {
		result += "Line ";
		result += std::to_string(number);
		result += ":";
		result += rows;
		result += newline;
		++number;
	}
	return result;
}

std::string Document::read_line() 
{
	if (this->data.size() < this->counter) {
		throw std::out_of_range ("It is out of range!");
	}

	int row = this->counter - 1;
	this->counter = this->counter + 1;
	return this->data[row];
}

std::string Document::read_line(const unsigned line) 
{

	if (line < 1) {
		throw std::out_of_range("The value is out of range!");
	}


	if (this->data.size() < line/* this->counter*/) {
		throw std::out_of_range("The value is out of range!");
	}

	this->counter = line + 1;

	int row = line - 1;
	return this->data[row];
}