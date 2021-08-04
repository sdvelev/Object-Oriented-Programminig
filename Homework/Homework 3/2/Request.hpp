#pragma once

#include<iostream>
#include<string>

using namespace std;

class Request {
protected:
	string message;
	string sender;
	static int counter;
	int ID;

	void setMessage(const string& message);
	void setSender(const string& sender);
public:
	Request();
	Request(const string& message, const string& sender);

	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
};