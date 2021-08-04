#include<iostream>
#include<string>
#include"Subscriber.hpp"
#include"MovingAverager.hpp"


MovingAverager::MovingAverager(std::string id, size_t windowSize) : id(id), windowSize(windowSize)
{

}

void MovingAverager::signal(const Message& _message)
{
	this->messagesData.push_back(_message.data);
}

Subscriber* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}

int MovingAverager::read() const
{

	if (this->messagesData.size() == 0 || this->windowSize <= 0) {
		return 0;
	}

	vector<int> lastElements;


	for (int i = (int) this->messagesData.size() - (int) this->windowSize; i < (int) this->messagesData.size(); i++) {
		if (i >= 0) {
			lastElements.push_back(this->messagesData[i]);
		}
	}

	double sum = 0;

	for (int i = 0; i < lastElements.size(); i++) {
		sum += lastElements[i];
	}

	if (sum == 0) {
		return 0;
	}

	int result;

	if (this->windowSize > this->messagesData.size()) {
		result = (sum / this->messagesData.size());
	}
	else {
		result = (sum / this->windowSize);
	}

	return result;
}
