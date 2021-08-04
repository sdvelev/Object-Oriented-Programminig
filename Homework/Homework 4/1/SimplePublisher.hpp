#pragma once
#include<iostream>
#include<vector>
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include"Subscriber.hpp"
#include"Publisher.hpp"

using namespace std;

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as 
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher : public Publisher {
public:
	SimplePublisher();
	SimplePublisher(Averager* _averager);
	SimplePublisher(MovingAverager* _movingAverager);
	SimplePublisher(PeriodicSampler* _periodicSampler);


	// subscribe registers a Subscriber to start receiving messages
	void subscribe(Averager* _averager);
	void subscribe(MovingAverager* _movingAverager);
	void subscribe(PeriodicSampler* _periodicSampler);

	// unsubscribe removes a Subscriber from the Publisher
	// Subscribers are removed based on their `id`
	// id's will always be unique
	void unsubscribe(Averager* _averager);
	void unsubscribe(MovingAverager* _movingAverager);
	void unsubscribe(PeriodicSampler* _periodicSampler);

	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	void signal(const Message&);
};