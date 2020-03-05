
#pragma once

#include <deque>
#include "Operand.hpp"
#include "Operand.cpp"
#include "OperandFactory.hpp"
#include "Exceptions.hpp"

class VMLogic
{
public:

    VMLogic();

	void	push(eOperandType type, const std::string &value);
	void	pop();
	void	dump();
	void	assert(eOperandType type, const std::string &value);
	void	add();
	void	sub();
	void	mul();
	void	div();
	void	mod();
	void	print();
	void	exit();
	void    top();
	void    type();

	void	executeCommand(const std::string &funcName);
	void	executeCommand(const std::string &funcName, eOperandType type, const std::string &value);

	bool    getIsExitPresent() const;

	~VMLogic() = default;

private:

    VMLogic(VMLogic const &);
    VMLogic &operator=(VMLogic const &);
    
	std::deque<IOperand *>	_registers;
	static std::pair<std::string, void (VMLogic::*)()>	_funcsWithoutParams[];
    static std::pair<std::string, void (VMLogic::*)(eOperandType type, const std::string &)>	_funcsWithParams[];
    
    
    OperandFactory _factory;
    bool    _isExitPresent;
};
