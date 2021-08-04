
#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too
#include<iostream>
#include "Error.hpp"
#include "Optional.hpp"

using namespace std;

template<typename T>

class Result {
private:
    T item;
    std::string error_message;
    bool error;
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

     bool operator==(const T& rhs);
     bool operator==(const Error& rhs);
    //friend bool operator==(const Result<T>& lhs, Error rhs);
   // friend bool operator==(const Result<T>& lhs, const Error& rhs);
    Optional<T> get_result() const;
    Optional<Error> get_error() const;

};

template<typename T>
Result<T>::Result() {
    this->item = T();
    this->error_message = "";
    this->error = false;
}


template<typename T>
Result<T>::Result(const T& result) {
    this->item = result;
    this->error = false;
}


template<typename T>
Result<T>::Result(const std::string& error_message) {
    this->error_message = error_message;
    this->error = true;
}


template<typename T>
bool Result<T>::operator==(const T& rhs) {
   // if(T() == Error()){}
    //cout << "I an here!" << endl;
     if (this->error == false) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool Result<T>::operator==(const Error& rhs) {
    // if(T() == Error()){}
     //cout << "I an here!" << endl;
    if (this->error == true) {
        return true;
    }
    else {
        return false;
    }
}

/*
template<typename T>
bool operator==(const Result<T>& lhs, Error rhs) {
    if (lhs.error == true) {
        return true;
    }
    else {
        return false;
    }
}*/

/*template<typename T>
bool operator==(const Result<T>& lhs, const Error& rhs) {
    if (lhs.error == true) {
        return true;
    }
    else {
        return false;
    }
}*/





/*
template<typename T>
bool operator==(const Result<T>& lhs, const T& rhs) {
   
}

template<typename T>
bool operator==(const Result<T>& lhs, const Error& rhs) {
    if (lhs.error == true) {
        return true;
    }
    else {
        return false;
    }
}*/

template<typename T>
Optional<T> Result<T>::get_result() const {
    Optional<T> a(item);
   // a.setItem(this->item);
    return a;
}


template<typename T>
Optional<Error> Result<T>::get_error() const {
    Optional<Error> a (error_message);
   // a.item = this->error_message;
    return a;
}