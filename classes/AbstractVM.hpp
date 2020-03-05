#pragma once

#include <iostream>
#include <regex>
#include <string>
#include <limits>
#include <stack>
#include <sstream>
#include <cmath>
#include "Sign.hpp"
#include "Number.hpp"
#include "Calculator.hpp"
#include <fstream>
#include "VMLogic.hpp"
#include "Lexer.hpp"

class AbstractVM {
    
public:
    AbstractVM();
    
    void launch(int argc, char *argv[]);
    int  getLine();
    int  getPrintLine() const;
    
    ~AbstractVM() = default;
    
private:
    void terminateExecutionFromTerminal(std::cmatch lexerResult, VMLogic &vmLogic);
    void lexerParser(std::string &str, VMLogic &vmLogic, int argc);
    
    AbstractVM(AbstractVM const &);
    AbstractVM &operator=(AbstractVM const &);
    
    int  _line;
    bool _printLine;
    int  _check;
};



