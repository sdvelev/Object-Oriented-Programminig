#include<iostream>
#include<string>
#include"LeavingRequest.hpp"

LeavingRequest::LeavingRequest() : Request() {}

LeavingRequest::LeavingRequest(const string& sender) : Request("I want to leave!", sender) {}

