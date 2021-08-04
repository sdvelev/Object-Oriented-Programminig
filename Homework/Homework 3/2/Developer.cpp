#include<iostream>
#include<string>
#include<vector>
#include"LeavingRequest.hpp"
#include"PromotionRequest.hpp"
#include"Developer.hpp"
#include"TeamLead.hpp"

Developer::Developer() {
	this->name = "";
	this->salary = 0;
	this->teamLead = nullptr;
}

Developer::Developer(const string& name) {
	this->name = name; 
	this->salary = 0;
	this->teamLead = nullptr;
}

string Developer::getName() const {
	return this->name;
}

double Developer::getSalary() const {
	return this->salary;
}

TeamLead* Developer::getTeamLead() const {
	return this->teamLead;
}

void Developer::setInitialSalary(double amount) {
	if (this->salary == 0) {
		this->salary = amount;
	}
}

void Developer::setName(string name) {
	this->name = name;
}

void Developer::setSalary(double salary) {
	this->salary = salary;
}

void Developer::setTeamLead(TeamLead* teamLead) {
	this->teamLead = teamLead;
}

void Developer::sendLeavingRequest() {

	if (this->teamLead != nullptr) {
		LeavingRequest _leavingRequest(this->name);
		this->teamLead->addLeavingRequest(_leavingRequest);
	}
}

void Developer::sendPromotionRequest(double amount) {
	
	if (this->teamLead != nullptr) {
		PromotionRequest _promotionRequest(this->name, amount);
		this->teamLead->addPromotionRequest(_promotionRequest);
	}
}