#pragma once

#include <string>
#include <regex>


class Lexer {

public:
    Lexer();

    bool resultOfRegularWithArguments(std::string &str);
    bool resultOfRegularWithComment(std::string &str);
    bool resultOfRegularWithoutArguments(std::string &str);

    std::cmatch getResult() const;

    ~Lexer() = default;

private:

    Lexer(Lexer const &);
    Lexer &operator=(Lexer const &);


    std::regex _regularWithArguments;
    std::regex _regularWithoutArguments;
    std::regex _regularWithComment;

    std::cmatch _result;
};



