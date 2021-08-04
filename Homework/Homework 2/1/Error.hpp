#pragma once
#include <string>
class Error {
private:
    std::string message;
    bool error;
public:
    Error(const std::string& message = "");
    std::string get_message() const;
};