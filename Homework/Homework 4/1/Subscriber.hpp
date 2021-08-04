#pragma once

#include<iostream>
#include<vector>
#include<string>
#include"Message.hpp"

using namespace std;

class Subscriber {
protected:
	vector<int> messagesData;
public:

	Subscriber() = default;

	virtual void signal(const Message& _message) = 0;

	virtual int read() const = 0;

	virtual Subscriber* clone() const = 0;

	virtual ~Subscriber() = default;
};