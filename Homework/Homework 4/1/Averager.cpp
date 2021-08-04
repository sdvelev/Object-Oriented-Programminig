#include<iostream>
#include<string>
#include"Averager.hpp"

Averager::Averager(std::string id) : id(id) {
}

void Averager::signal(const Message& _message)
{
	this->messagesData.push_back(_message.data);
}

Subscriber* Averager::clone() const
{
	return new Averager(*this);
}


int Averager::read() const
{
	if (this->messagesData.size() == 0) {
		return 0;
	}

	double sum = 0;
	for (auto data : this->messagesData) {
		sum += data;
	}

	int result = sum / this->messagesData.size();
	return result;
}
