#include<iostream>
#include"LimitedCounter.hpp"

using namespace std;

LimitedCounter::LimitedCounter() : Counter() {
	this->max = 0;
}

LimitedCounter::LimitedCounter(int max) : Counter() {
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial) : Counter(initial)  {
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step) : Counter(initial,step) {
	this->max = max;
}

void LimitedCounter::increment() {
	if ((this->initial + (int) this->step) <= this->max) {
		Counter::increment();
	}
}

int LimitedCounter::getMax() const {
	return this->max;
}


