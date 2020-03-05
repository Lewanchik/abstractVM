
#include "Parser.hpp"


namespace {

    std::pair<std::string, eOperandType> stringType[NUMBEROFSTRINGTYPES] = {
            {"int8", Int8},
            {"int16", Int16},
            {"int32", Int32},
            {"float", Float},
            {"double", Double}
    };

    eOperandType getType(std::string const &string)
    {
        for (const auto& a : stringType)
        {
            if (a.first == string)
                return (a.second);
        }
        throw (std::logic_error("stringType"));
    }
}


void Parser::executeCommandWithArguments(VMLogic &vmLogic)
{
    _command = _result[1];
    _type = _result[2];
    _value = _result[3];
    _stringStream << std::setprecision(MAX_PRECISION) << _calculator.calculatePolishString(_value);
    vmLogic.executeCommand(_command, getType(_type), _stringStream.str());
    _stringStream.str("");
    clearStrings();
}

void Parser::executeCommnadWithoutArguments(VMLogic &vmLogic)
{
    _command = _result[1];
    vmLogic.executeCommand(_command);
    clearStrings();
}

void Parser::clearStrings()
{
    _command = "";
    _type = "";
    _value = "";
}

void Parser::setResult(const std::cmatch &result)
{
    _result = result;
}