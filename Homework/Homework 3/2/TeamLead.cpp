#include<iostream>
#include<string>
#include<vector>
#include"TeamLead.hpp"

using namespace std;

TeamLead::TeamLead() : Developer() {}

TeamLead::TeamLead(const string& name, double salary) {
	this->name = name;
	this->salary = salary;
	this->teamLead = this;
}

vector<LeavingRequest> TeamLead::getLeavingRequests() const {
	return this->leavingRequests;

}
vector<PromotionRequest> TeamLead::getPromotionRequests() const {
	return this->promotionRequests;
}

vector<Developer*> TeamLead::getTeam() const {
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
	
	if (developer != nullptr) {
		if (developer->getTeamLead() == nullptr) {
			this->team.push_back(developer);
			developer->setInitialSalary(salary);
			developer->setTeamLead(this);
		}
	}
}

void TeamLead::removeDeveloperFromTeam(const string& name) {
	for (int i = this->getTeam().size() - 1; i >= 0; i--) {
		if (this->getTeam()[i]->getName() == name) {
			//this->team[i]->setSalary(0);
		    this->team[i]->setTeamLead(nullptr);
			this->team.erase(team.begin() + i);
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount) {
	for (int i = 0; i < this->getTeam().size(); i++) {
		this->team[i]->setSalary(this->getTeam()[i]->getSalary() + amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
	for (int i = 0; i < this->getTeam().size(); i++) {
		this->team[i]->setSalary(this->getTeam()[i]->getSalary() - amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
	this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
	this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {

	for (int i = 0; i < this->leavingRequests.size(); i++) {
		for (int j = 0; j < this->team.size(); j++) {
			if (this->leavingRequests[i].getSender() == this->getTeam()[j]->getName()) {
				this->team[j]->setTeamLead(nullptr);
				this->removeDeveloperFromTeam(this->leavingRequests[i].getSender());
				this->leavingRequests.erase(leavingRequests.begin() + i);
			}
		}
	}
}

void TeamLead::fulfillPromotionRequests() {
	
	for (int i = 0; i < this->promotionRequests.size(); i++) {
		for (int j = 0; j < this->team.size(); j++) {
			if (this->promotionRequests[i].getSender() == this->getTeam()[j]->getName()) {
				this->team[j]->setSalary(this->team[j]->getSalary() + this->promotionRequests[i].getAmount());
				this->promotionRequests.erase(promotionRequests.begin() + i);
			}
		}
	}
}

	
	