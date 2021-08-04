#pragma once

#include<iostream>
#include"TwowayCounter.hpp"
#include"LimitedCounter.hpp"

using namespace std;

class LimitedTwowayCounter :  public TwowayCounter,  public LimitedCounter{
protected:
	int min;
public:
	LimitedTwowayCounter();
	LimitedTwowayCounter(int min, int max);
	LimitedTwowayCounter(int min, int max, int initial);
	LimitedTwowayCounter(int min, int max, int initial, unsigned step);

	void increment();
	void decrement();
	int getMin() const;
};