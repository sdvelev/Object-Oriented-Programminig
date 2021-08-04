#include<iostream>
#include"LimitedTwowayCounter.hpp"

using namespace std;

LimitedTwowayCounter::LimitedTwowayCounter() : Counter() , TwowayCounter(), LimitedCounter() {
	this->min = 0;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) : Counter(), TwowayCounter(), LimitedCounter(max){
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial) : Counter(initial),
 TwowayCounter(initial), LimitedCounter(max, initial) {
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step)
	: Counter(initial,step), TwowayCounter(initial, step), LimitedCounter(max, initial, step) {
	this->min = min;
}

void LimitedTwowayCounter::increment() {
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement() {
	if ((this->getTotal() - (int) this->getStep()) >= this->getMin()) {
		TwowayCounter::decrement();
	}
}

int LimitedTwowayCounter::getMin() const {
	return this->min;
}








