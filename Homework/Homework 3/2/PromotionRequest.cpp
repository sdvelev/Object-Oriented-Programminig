#include<iostream>
#include<string>
#include"PromotionRequest.hpp"

using namespace std;

PromotionRequest::PromotionRequest() : Request() {
	this->amount = 0;
}

PromotionRequest::PromotionRequest(const string& sender, double amount) : Request("I want a raise!", sender) {
	this->amount = amount;
}

double PromotionRequest::getAmount() const {
	return this->amount;
}