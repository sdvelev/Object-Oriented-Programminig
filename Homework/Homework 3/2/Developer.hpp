#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class TeamLead;

class Developer {
	friend class TeamLead;
protected:
	string name;
	double salary;
	TeamLead * teamLead;

	void setSalary(double salary);
	void setTeamLead(TeamLead* teamLead);
	void setName(string name);
public:
	Developer();
	Developer(const string& name);

	string getName() const;
	double getSalary() const;
	TeamLead * getTeamLead() const;

	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
};