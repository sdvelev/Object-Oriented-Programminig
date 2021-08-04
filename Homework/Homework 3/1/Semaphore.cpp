#include<iostream>
#include"Semaphore.hpp"

using namespace std;

Semaphore::Semaphore() : LimitedTwowayCounter(0,1)  {}

Semaphore::Semaphore(bool state) : LimitedTwowayCounter(0, 1) {
	if (state) {
		this->setInitial(1);
	}
	else {
		this->setInitial(0);
	}
}


bool Semaphore::isAvailable() const{
	if (this->getTotal() > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Semaphore::wait() {
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal() {
	LimitedTwowayCounter::increment();
}

