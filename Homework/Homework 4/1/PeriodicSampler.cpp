#include<iostream>
#include<string>
#include<vector>
#include"PeriodicSampler.hpp"

using namespace std;

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : id(id), period(period) {}

void PeriodicSampler::signal(const Message& _message)
{
	this->messagesData.push_back(_message.data);
}

Subscriber* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}

int PeriodicSampler::read() const
{
	if (this->messagesData.size() == 0) {
		return 0;
	}

	for (int i = (this->messagesData.size() - 1); i >= 0; i--) {
		if (i % this->period == 0) {
			return this->messagesData[i];
		}
	}
}
