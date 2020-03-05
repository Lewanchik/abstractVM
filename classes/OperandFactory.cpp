#include "OperandFactory.hpp"
#include "Operand.cpp"

std::pair<
		eOperandType,
		IOperand const *(OperandFactory::*)( std::string const & value ) const
> OperandFactory::_createFunctions[] = {
		{Int8, &OperandFactory::createInt8},
		{Int16, &OperandFactory::createInt16},
		{Int32, &OperandFactory::createInt32},
		{Float, &OperandFactory::createFloat},
		{Double, &OperandFactory::createDouble}
};

IOperand const *
OperandFactory::createOperand(eOperandType type, std::string const &value) const
{
	for (auto func : _createFunctions)
	{
		if (func.first == type)
			return (this->*func.second)(value);
	}
	return nullptr;
}

IOperand const *OperandFactory::createInt8(std::string const &value) const
{
	return dynamic_cast<IOperand const *>(new Operand<int8_t>(Int8, value));
}

IOperand const *OperandFactory::createInt16(std::string const &value) const
{
	return dynamic_cast<IOperand const *>(new Operand<int16_t>(Int16, value));
}

IOperand const *OperandFactory::createInt32(std::string const &value) const
{
	return dynamic_cast<IOperand const *>(new Operand<int32_t>(Int32, value));
}

IOperand const *OperandFactory::createFloat(std::string const &value) const
{
	return dynamic_cast<IOperand const *>(new Operand<float>(Float, value));
}

IOperand const *OperandFactory::createDouble(std::string const &value) const
{
	return dynamic_cast<IOperand const *>(new Operand<double >(Double, value));
}

