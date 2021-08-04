#include<iostream>
#include<string>
#include<vector>
#include"BacklogPublisher.hpp"


BacklogPublisher::BacklogPublisher() : Publisher() {}

void BacklogPublisher::subscribe(Averager* _averager)
{
	if (_averager)
		this->averagers.push_back(_averager);
	else
		return;

		for (int i = 0; i < this->history.size(); i++) {
			_averager->signal(this->history[i]);
		}
}

void BacklogPublisher::subscribe(MovingAverager* _movingAverager)
{
	if (_movingAverager)
		this->movingAveragers.push_back(_movingAverager);
	else
		return;

		for (int i = 0; i < this->history.size(); i++) {
			_movingAverager->signal(this->history[i]);
		}
}

void BacklogPublisher::subscribe(PeriodicSampler* _periodSampler)
{
	if (_periodSampler)
		this->periodicSamplers.push_back(_periodSampler);
	else
		return;

		for (int i = 0; i < this->history.size(); i++) {
			_periodSampler->signal(this->history[i]);
		}
}

void BacklogPublisher::unsubscribe(Averager* _averager)
{
	if (_averager) {
		for (int i = 0; i < this->averagers.size(); i++) {
			if (this->averagers[i]->id == _averager->id) {
				this->averagers.erase(this->averagers.begin() + i);
				return;
			}
		}
	}
	
}

void BacklogPublisher::unsubscribe(MovingAverager* _movingAverager)
{
	if (_movingAverager) {
		for (int i = 0; i < this->movingAveragers.size(); i++) {
			if (this->movingAveragers[i]->id == _movingAverager->id) {
				this->movingAveragers.erase(this->movingAveragers.begin() + i);
				return;
			}
		}
	}
	
}

void BacklogPublisher::unsubscribe(PeriodicSampler* _periodicSampler)
{
	if (_periodicSampler) {
		for (int i = 0; i < this->periodicSamplers.size(); i++) {
			if (this->periodicSamplers[i]->id == _periodicSampler->id) {
				this->periodicSamplers.erase(this->periodicSamplers.begin() + i);
				return;
			}
		}
	}
}

void BacklogPublisher::signal(const Message& _message) 
{
	this->history.push_back(_message);
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
