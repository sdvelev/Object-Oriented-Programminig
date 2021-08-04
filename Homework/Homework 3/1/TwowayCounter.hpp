#pragma once

#include<iostream>
#include"Counter.hpp"

using namespace std;

class TwowayCounter : virtual public Counter {
private:
public:
	TwowayCounter();
	TwowayCounter(int initial);
	TwowayCounter(int initial, unsigned step);

	void decrement();
};