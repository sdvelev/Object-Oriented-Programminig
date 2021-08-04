#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Averager.hpp"
#include"MovingAverager.hpp"
#include"PeriodicSampler.hpp"

using namespace std;

class Publisher {
protected:
	vector<Averager*> averagers;
	vector<MovingAverager*> movingAveragers;
	vector<PeriodicSampler*> periodicSamplers;
public:
	Publisher();
	Publisher(Averager* _averager);
	Publisher(MovingAverager* _movingAverager);
	Publisher(PeriodicSampler* _periodicSampler);


	virtual void subscribe(Averager* _averager) = 0;
	virtual void subscribe(MovingAverager* _movingAverager) = 0;
	virtual void subscribe(PeriodicSampler* _periodicSampler) = 0;

	// unsubscribe removes a Subscriber from the Publisher
	// Subscribers are removed based on their `id`
	// id's will always be unique
	virtual void unsubscribe(Averager* _averager) = 0;
	virtual void unsubscribe(MovingAverager* _movingAverager) = 0;
	virtual void unsubscribe(PeriodicSampler* _periodicSampler) = 0;

	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	virtual void signal(const Message& _message) = 0;

};