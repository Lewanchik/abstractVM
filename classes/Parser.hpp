#pragma once


#include <regex>
#include <sstream>
#include "Calculator.hpp"
#include <iomanip>
#include "../inc/includes.hpp"
#include "VMLogic.hpp"

class Parser {
public:
    Parser() = default;

    void executeCommandWithArguments(VMLogic &vmLogic);
    void executeCommnadWithoutArguments(VMLogic &vmLogic);

    void setResult(const std::cmatch &result);
private:

    void clearStrings();

    Calculator  _calculator;
    std::string _command;
    std::string _type;
    std::string _value;

    std::cmatch _result;
    std::stringstream _stringStream;
};



