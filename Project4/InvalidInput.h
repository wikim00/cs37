#ifndef INVALID_INPUT_EXCEPTION_H
#define INVALID_INPUT_EXCEPTION_H

#include <string>
#include <iostream>
using namespace std;

class InvalidInput {
private:
    const string message;

public:
    InvalidInput(const std::string& input) : message("Invalid input \"" + input + "\".\n") {}

    void reason() const {
        cout << message;
    }
};

#endif // INVALID_INPUT_EXCEPTION_H
