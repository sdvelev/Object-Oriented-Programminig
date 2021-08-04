#pragma once

#include<iostream>
#include<string>
#include"Comparable.hpp"
#include"Debug.hpp"
#include"Serializable.hpp"

using namespace std;

class Object : public Comparable, public Debug, public Serializable {
protected:
    string name;
    string location;
    string extension;
public:
    Object();
    Object(const std::string& name, const std::string& location, const std::string& extension);

    Object(const Object& other) = default;
    Object& operator=(const Object& rhs) = default;

    virtual Object* clone() const = 0;

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;

    virtual ~Object() = default;
};