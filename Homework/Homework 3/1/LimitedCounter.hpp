#pragma once

#include<iostream>
#include"Counter.hpp"

class LimitedCounter : virtual public Counter {
protected:
	int max;
public:
	LimitedCounter();
	LimitedCounter(int max);
	LimitedCounter(int max, int initial);
	LimitedCounter(int max, int initial, unsigned step);

	void increment();
	int getMax() const;
};