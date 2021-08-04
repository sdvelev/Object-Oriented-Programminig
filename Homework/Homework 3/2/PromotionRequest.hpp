#pragma once
#include<iostream>
#include<string>
#include "Request.hpp"

using namespace std;

class PromotionRequest : public Request {
private:
	double amount;
public:
	PromotionRequest();
	PromotionRequest(const string& sender, double amount);

	double getAmount() const;
};