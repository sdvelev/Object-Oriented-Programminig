#include<iostream>
#include<string>
#include"Object.hpp"

using namespace std;

Object::Object()
{
	this->name = "";
	this->location = "";
	this->extension = "";
}

Object::Object(const std::string& _name, const std::string& _location, const std::string& _extension)
{
	this->name = _name;
	this->location = _location;
	this->extension = _extension;
}

std::string Object::get_name() const
{
	return this->name;
}

std::string Object::get_location() const
{
	return this->location;
}

std::string Object::get_extension() const
{
	return this->extension;
}

std::string Object::get_fullpath() const
{
	string result;
	result = this->location;
	result += "/";
	result += this->name;
	result += ".";
	result += this->extension;
	return result;
}
