
#pragma once

#include "stack"
#include "string"
#include "Sign.hpp"
#include "Number.hpp"
#include <cmath>


class Calculator {
public:
    Calculator() = default;

    double    calculatePolishString(std::string &string);

    ~Calculator() = default;

private:

    Calculator(Calculator const &);
    Calculator &operator=(Calculator const &);
    
    std::vector<SignOrNumber *> createPolishString(std::string &input);
};


