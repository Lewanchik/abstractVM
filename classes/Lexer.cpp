#include "Lexer.hpp"


Lexer::Lexer(): _regularWithArguments(R"(\s*(push|assert)\s*(int8|int16|int32|float|double)\(((\s*(\(|\))\s*)*(\s*[\+-]?\d{1,}(\.\d{0,})?\s*)(\s*(\(|\))\s*)*((\s*[-\+\*/]\s*)(\s*(\(|\))\s*)*(\s*[\+-]?\d{1,}(\.\d{0,})?\s*)(\s*(\(|\))\s*)*)*)\)\s*(;[\d\D]{0,})?)"),
 _regularWithoutArguments(R"(\s*(pop|dump|add|sub|mul|div|mod|print|exit|top|type)\s*(;[\d\D]{0,})?)") , _regularWithComment(R"(\s*(;[\d\D]{0,})?)")
{}

bool Lexer::resultOfRegularWithArguments(std::string &str)
{
    return std::regex_match(str.c_str(), _result, _regularWithArguments);
}

bool Lexer::resultOfRegularWithComment(std::string &str)
{
    return std::regex_match(str.c_str(), _result, _regularWithComment);
}

bool Lexer::resultOfRegularWithoutArguments(std::string &str)
{
    return std::regex_match(str.c_str(), _result, _regularWithoutArguments);
}

std::cmatch Lexer::getResult() const
{
    return _result;
}