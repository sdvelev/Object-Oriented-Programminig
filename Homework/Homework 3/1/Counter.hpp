#pragma once

#include<iostream>

using namespace std;

class Counter {
protected:
	int initial;
	unsigned int step;

	void setInitial(int initial);
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);

	virtual void increment();
	int getTotal() const;
	unsigned int getStep() const;

};