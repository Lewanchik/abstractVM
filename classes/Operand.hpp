
#pragma once

#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "Exceptions.hpp"
#include <iomanip>
#include <cmath>
#include <sstream>


template <class T>
class Operand : public IOperand
{

public:
	Operand();

	explicit Operand(eOperandType operandType, std::string const &valueString);

	int getPrecision() const override; // Precision of the type of the instance

	eOperandType getType( ) const override; // Type of the instance

	T getValueScalar() const;

	IOperand const * operator+( IOperand const & rhs ) const override; // Sum

	IOperand const * operator-( IOperand const & rhs ) const override; // Difference

	IOperand const * operator*( IOperand const & rhs ) const override; // Product

	IOperand const * operator/( IOperand const & rhs ) const override; // Quotient

	IOperand const * operator%( IOperand const & rhs ) const override; // Modulo

	std::string const &toString() const override;

	~Operand() override;

private:

    Operand(Operand const &);
    Operand &operator=(Operand const &);
    
	T				_valueScalar;
	std::string		_valueString;
    eOperandType	_operandType;
};

