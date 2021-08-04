#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Object.hpp"

using namespace std;

class KeyValueDatabase : public Object {
private:
    vector<pair<string, int>> data;
public:
    KeyValueDatabase();
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    virtual Object* clone() const;

    virtual bool operator==(const Comparable* rhs) const;
    virtual bool operator!=(const Comparable* rhs) const;

    virtual string to_string() const;
    virtual void from_string(const string& other);

    virtual string debug_print() const;
};