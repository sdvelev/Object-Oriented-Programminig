#pragma once

#include<iostream>
#include<string>

using namespace std;

class Serializable {
public:
	Serializable() = default;

	virtual string to_string() const = 0;
	virtual void from_string(const string& other) = 0;
};