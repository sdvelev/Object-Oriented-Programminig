#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Developer.hpp"
#include"LeavingRequest.hpp"
#include"PromotionRequest.hpp"

using namespace std;

class TeamLead : public Developer {
private:
	vector<Developer *> team;	
	vector<LeavingRequest> leavingRequests;
	vector<PromotionRequest> promotionRequests;
public:
	TeamLead();
	TeamLead(const string& name, double salary);

	vector<LeavingRequest> getLeavingRequests() const;
	vector<PromotionRequest> getPromotionRequests() const;

	vector<Developer *> getTeam() const;
	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const string& name);

	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);

	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();

};