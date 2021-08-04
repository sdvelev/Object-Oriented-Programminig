#include<iostream>
#include<vector>
#include "SimplePublisher.hpp"


SimplePublisher::SimplePublisher() : Publisher() {}

SimplePublisher::SimplePublisher(Averager* _averager) : Publisher(_averager) {}

SimplePublisher::SimplePublisher(MovingAverager* _movingAverager) : Publisher(_movingAverager) {}

SimplePublisher::SimplePublisher(PeriodicSampler* _periodicSampler) : Publisher(_periodicSampler) {}

void SimplePublisher::subscribe(Averager* _averager)
{
	if(_averager)
		this->averagers.push_back(_averager);
}

void SimplePublisher::subscribe(MovingAverager* _movingAverager)
{
	if(_movingAverager)
		this->movingAveragers.push_back(_movingAverager);
}

void SimplePublisher::subscribe(PeriodicSampler* _periodicSampler)
{
	if(_periodicSampler)
		this->periodicSamplers.push_back(_periodicSampler);
}

void SimplePublisher::unsubscribe(Averager* _averager)
{
	for (int i = 0; i < this->averagers.size(); i++) {
		if (this->averagers[i]->id == _averager->id) {
			this->averagers.erase(this->averagers.begin() + i);
			return;
		}
	}
}

void SimplePublisher::unsubscribe(MovingAverager* _movingAverager)
{
	for (int i = 0; i < this->movingAveragers.size(); i++) {
		if (this->movingAveragers[i]->id == _movingAverager->id) {
			this->movingAveragers.erase(this->movingAveragers.begin() + i);
			return;
		}
	}
}

void SimplePublisher::unsubscribe(PeriodicSampler* _periodicSampler)
{
	for (int i = 0; i < this->periodicSamplers.size(); i++) {
		if (this->periodicSamplers[i]->id == _periodicSampler->id) {
			this->periodicSamplers.erase(this->periodicSamplers.begin() + i);
			return;
		}
	}
}

void SimplePublisher::signal(const Message& _message) 
{
	for (int i = 0; i < this->averagers.size(); i++) {
		this->averagers[i]->signal(_message);
	}

	for (int i = 0; i < this->movingAveragers.size(); i++) {
		this->movingAveragers[i]->signal(_message);
	}

	for (int i = 0; i < this->periodicSamplers.size(); i++) {
		this->periodicSamplers[i]->signal(_message);
	}
}

