#include<iostream>
#include<string>
#include<vector>
#include"Repository.hpp"

using namespace std;

Repository::Repository() {}

void Repository::add(Averager* _averager)
{
	if (_averager) {
		this->subscribers.push_back(_averager->clone());
	}
}

void Repository::add(MovingAverager* _movingAverager)
{
	if (_movingAverager) {
		this->subscribers.push_back(_movingAverager ->clone());
	}
}

void Repository::add(PeriodicSampler* _periodicSampler)
{
	if (_periodicSampler) {
		this->subscribers.push_back(_periodicSampler->clone());
	}
}

Repository::Repository(const Repository& other)
{
	for (int i = 0; i < other.subscribers.size(); i++) {
		this->subscribers.push_back(other.subscribers[i]->clone());
	}
}

Repository& Repository::operator=(const Repository& rhs)
{
	if (this != &rhs) {
		for (int i = 0; i < this->subscribers.size(); i++) {
			delete this->subscribers[i];
		}
		this->subscribers.clear();

		for (int i = 0; i < rhs.subscribers.size(); i++) {
			this->subscribers.push_back(rhs.subscribers[i]->clone());
		}
	}
	return *this;
}

Subscriber* Repository::get(const std::string& id) const
{
	for (int i = 0; i < this->subscribers.size(); i++) {
		Averager* averagerPtr = dynamic_cast<Averager*>(this->subscribers[i]);
		MovingAverager* movingAveragerPtr = dynamic_cast<MovingAverager*>(this->subscribers[i]);
		PeriodicSampler* periodicSamplerPtr = dynamic_cast<PeriodicSampler*>(this->subscribers[i]);
		
		if (averagerPtr) {
			if (averagerPtr->id == id) {
				return averagerPtr;
			}
		}

		if (movingAveragerPtr) {
			if (movingAveragerPtr->id == id) {
				return movingAveragerPtr;
			}
		}

		if (periodicSamplerPtr) {
			if (periodicSamplerPtr->id == id) {
				return periodicSamplerPtr;
			}
		}
	}
	return nullptr;
}

Repository::~Repository()
{
	for (int i = 0; i < this->subscribers.size(); i++) {
		delete this->subscribers[i];
	}
}
