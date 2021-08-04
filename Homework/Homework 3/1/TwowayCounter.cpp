#include<iostream>
#include"TwowayCounter.hpp"

using namespace std;

TwowayCounter::TwowayCounter() :Counter() {}

TwowayCounter::TwowayCounter(int initial) : Counter(initial) {}

TwowayCounter::TwowayCounter(int initial, unsigned step) : Counter(initial, step) {}

void TwowayCounter::decrement() {
	this->initial -= this->step;
}
