#include "Operand.hpp"

class OperandFactory;

namespace
{
    template<class K>
    void check_adding(K first, K second)
    {
        K sum = first + second;
        if ((first < 0) == (second < 0))
        {
            if (first < 0 && sum > second)
                throw Exceptions::Underflow();
            else if (sum < second)
                throw Exceptions::Overflow();
        }
    }

    template<class T>
    void
    check_mul(T first, T second)
    {
        T max = std::numeric_limits<T>::max();
        T abs_a = (first < 0 ? first * -1 : first);
        T abs_b = (second < 0 ? second * -1 : second);
        if (abs_a > max / abs_b)
        {
            if ((first < 0) && (second < 0))
                throw Exceptions::Overflow();
            else if ((first > 0) && (second > 0))
                throw Exceptions::Overflow();
            else
                throw Exceptions::Underflow();
        }
    }
}

template <class T>
Operand<T>::Operand()
{
	_operandType = Int8;
	this->_valueString = "0";
	this->_valueScalar = 0;
}

template <class T>
Operand<T>::Operand(eOperandType operandType, std::string const &valueString) :
		_operandType(operandType)
{
	std::stringstream ss;
	double convert;

	try
	{
		if (_operandType == Float)
			convert = std::stof(valueString);
		else
			convert = std::stod(valueString);
	}
	catch (std::exception &e)
	{
        if (valueString[0] != '-')
            throw (Exceptions::Overflow());
        else
            throw (Exceptions::Underflow());
	}
	_valueScalar = convert;
	if (_operandType < Float && _valueScalar != static_cast<long>(convert))
	{
        if (valueString[0] != '-')
            throw (Exceptions::Overflow());
        else
            throw (Exceptions::Underflow());
    }
	_valueString = std::to_string(_valueScalar);

}

template <class T>
T Operand<T>::getValueScalar() const
{
    return _valueScalar;
}

template <class T>
eOperandType	Operand<T>::getType() const
{
    return _operandType;
}

template <class T>
std::string const	&Operand<T>::toString() const
{
    return _valueString;
}

template <class T>
int	Operand<T>::getPrecision() const
{
	if (_operandType < Float)
		return 0;
	else
	{
		if (_valueString.find(".") != std::string::npos)
		{
			const std::string &tmp = _valueString.substr(_valueString.find("."));
			return tmp.size() - 1;
		}
		else
			return 0;
	}
}

template <class T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const
{
	const IOperand *result;
	std::string tmp;
	double number1 = 0;
    double number2 = 0;
    size_t  i;

    number1 = std::stod(rhs.toString(), &i);
    i = 0;
    number2 = std::stod(this->toString(), &i);
	check_adding(number1, number2);
    tmp = std::to_string(number1 + number2);
	if (rhs.getType() > this->_operandType)
        result = OperandFactory().createOperand(rhs.getType(), tmp);
	else
        result = OperandFactory().createOperand(_operandType, tmp);
	return (result);
}

template <class T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const
{
    const IOperand *result;
    std::string tmp;
    double number1 = 0;
    double number2 = 0;
    size_t  i;

    number2 = std::stod(rhs.toString(), &i);
    i = 0;
    number1 = std::stod(this->toString(), &i);
    check_adding(number1, (-1) * number2);
    tmp = std::to_string(number1 - number2);
    if (rhs.getType() > this->_operandType)
        result = OperandFactory().createOperand(rhs.getType(), tmp);
    else
        result = OperandFactory().createOperand(_operandType, tmp);
    return (result);
}

template <class T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const
{
    const IOperand *result;
    std::string tmp;
    double number1 = 0;
    double number2 = 0;
    size_t  i;

    number1 = std::stod(rhs.toString(), &i);
    i = 0;
    number2 = std::stod(this->toString(), &i);
    check_mul(number1, number2);
    tmp = std::to_string(number1 * number2);
    if (rhs.getType() > this->_operandType)
        result = OperandFactory().createOperand(rhs.getType(), tmp);
    else
        result = OperandFactory().createOperand(_operandType, tmp);
    return (result);
}

template <class T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const
{
    const IOperand *result;
    std::string tmp;
    double number1 = 0;
    double number2 = 0;
    size_t  i;

    number2 = std::stod(rhs.toString(), &i);
    i = 0;
    number1 = std::stod(this->toString(), &i);
    if (number2 == 0)
        throw (Exceptions::DivideZero());
    check_mul(number1, 1 / number2);
    tmp = std::to_string(number1 / number2);
    if (rhs.getType() > this->_operandType)
        result = OperandFactory().createOperand(rhs.getType(), tmp);
    else
        result = OperandFactory().createOperand(_operandType, tmp);
    return (result);
}

template <class T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const
{
	eOperandType rhsType;

	rhsType = rhs.getType();
	if (rhsType != Double && rhsType != Float && _operandType != Double && _operandType != Float)
	{
        const IOperand *result;
        std::string tmp;
        double number1 = 0;
        double number2 = 0;
        size_t  i;

        number2 = std::stod(rhs.toString(), &i);
        i = 0;
        number1 = std::stod(this->toString(), &i);
        if (number2 == 0)
            throw (Exceptions::ModuleZero());
        tmp = std::to_string(number1 / number2);
        if (rhs.getType() > this->_operandType)
            result = OperandFactory().createOperand(rhs.getType(), tmp);
        else
            result = OperandFactory().createOperand(_operandType, tmp);
        return (result);
	}
	else
		throw (std::logic_error("Only integers can be use with module"));
}


template <class T>
Operand<T>::~Operand()
{}
