
#include "AbstractVM.hpp"
#include "Parser.hpp"


int AbstractVM::getLine()
{
    if (_line == 0)
        _line++;
    return _line;
}

void AbstractVM::terminateExecutionFromTerminal(std::cmatch lexerResult, VMLogic &vmLogic)
{
    std::string comment;
    
    if (std::string(lexerResult[lexerResult.size() - 1])[0] == ';')
        comment = lexerResult[lexerResult.size() - 1];
    if (comment.find(";;") != std::string::npos)
    {
        if (!vmLogic.getIsExitPresent())
            throw std::logic_error("Exit is not present");
        exit(1);
    }
}

void AbstractVM::lexerParser(std::string &str, VMLogic &vmLogic, int argc)
{
    Lexer lexer;
    Parser parser;
    
    _check = 0;
    AbstractVM::_line++;
    if (lexer.resultOfRegularWithArguments(str))
    {
        _check++;
        parser.setResult(lexer.getResult());
        parser.executeCommandWithArguments(vmLogic);
    }
    else if (lexer.resultOfRegularWithoutArguments(str))
    {
        _check++;
        parser.setResult(lexer.getResult());
        parser.executeCommnadWithoutArguments(vmLogic);
    }
    if (str.find(";;") != std::string::npos || vmLogic.getIsExitPresent() || lexer.resultOfRegularWithComment(str))
    {
        if (argc == 1)
        {
            terminateExecutionFromTerminal(lexer.getResult(), vmLogic);
            if (str.find(";;") != std::string::npos)
            {
                if (!vmLogic.getIsExitPresent())
                {
                    throw std::logic_error("Exit is not present");
                }
                exit(1);
            }
        }
        return;
    }
    if (_check == 0)
        throw std::logic_error("Invalid command");
}

void AbstractVM::launch(int argc, char *argv[])
{
    std::string str;
    std::ifstream file(argv[1]);
    
    VMLogic vmLogic;
    
    if (argc > 2)
        throw std::logic_error("Two many arguments");
    if (argc == 2)
    {
        if (!file.is_open())
            throw std::logic_error("Can not open your file");
        _printLine = true;
        while (std::getline(file, str))
            lexerParser(str, vmLogic, argc);
    }
    if (argc == 1)
    {
        while (std::getline(std::cin, str))
        {
            _printLine = true;
            lexerParser(str, vmLogic, argc);
        }
    }
    if (!vmLogic.getIsExitPresent())
    {
        AbstractVM::_line++;
        throw std::logic_error("Exit is not present");
    }
}

int AbstractVM::getPrintLine() const
{
    return _printLine;
}

AbstractVM::AbstractVM()
{
    _line = 0;
    _printLine = false;
}
