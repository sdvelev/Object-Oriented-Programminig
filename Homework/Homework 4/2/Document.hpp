#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Object.hpp"

class Document : public Object {
private:
    vector<string> data;
    unsigned int counter;
public:
    Document();
    Document(const std::string& name, const std::string& location, const std::string& extension);

    Document(const Document& other);
    Document& operator=(const Document& rhs);


    void write_line(const std::string& line);

 
    virtual Object* clone() const;

    virtual bool operator==(const Comparable* rhs) const;
    virtual bool operator!=(const Comparable* rhs) const;

    virtual string to_string() const;
    virtual void from_string(const string& other);

    virtual string debug_print() const;

    std::string read_line();
    std::string read_line(const unsigned line);
};