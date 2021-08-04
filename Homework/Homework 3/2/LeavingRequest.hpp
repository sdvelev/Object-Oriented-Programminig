#pragma once

#include<iostream>
#include<string>
#include"Request.hpp"

class LeavingRequest : public Request {
public:
	LeavingRequest();
	LeavingRequest(const string& sender);
};