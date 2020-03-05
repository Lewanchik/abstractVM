
#include "AbstractVM.hpp"

namespace
{
    std::string usage = "usage: ./avm [file]\nAdditional commands:\ntop - shows value of the top of stack\ntype - shows type of the top of stack";
}

int main(int argc, char *argv[])
{
    AbstractVM abstactVm;

    if (argc > 1 && (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-help"))
    {
        std::cout << "\033[1;33m" << usage << "\033[0m" << std::endl;
        exit(1);
    }
    try
    {
        abstactVm.launch(argc, argv);
    }
    catch (std::exception &e)
    {
        if (abstactVm.getPrintLine())
            std::cout  <<  "\033[4;31m" << "Line " << abstactVm.getLine() << ": " <<  e.what() << "\033[0m" << std::endl;
        else
        {
            std::cout  <<  "\033[4;31m" <<  e.what() << "\033[0m" << std::endl;
        }
    }
}
