#pragma once

#include "Operand.hpp"

class OperandFactory
{
public:
	OperandFactory() = default;

	IOperand const * createOperand( eOperandType type, std::string const & value ) const;

	~OperandFactory() = default;

private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	OperandFactory(OperandFactory const &);
	OperandFactory &operator=(OperandFactory const &);

	static std::pair<
				eOperandType,
				IOperand const *(OperandFactory::*)( std::string const & value ) const
	        > _createFunctions[];
};
