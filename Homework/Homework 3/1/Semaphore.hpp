#pragma once

#include<iostream>
#include"LimitedTwowayCounter.hpp"

using namespace std;

class Semaphore :  protected LimitedTwowayCounter {
private:
public:
	Semaphore();
	Semaphore(bool state);

	bool isAvailable() const;
	void wait();
	void signal();

};