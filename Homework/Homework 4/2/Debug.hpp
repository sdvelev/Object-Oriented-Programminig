
#pragma once

#include<iostream>
#include<string>

using namespace std;

class Debug {
public:
	Debug() = default;

	virtual string debug_print() const = 0;
};