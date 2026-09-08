/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 15:18:30 by antuel            #+#    #+#             */
/*   Updated: 2026/09/08 13:49:23 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& copy) : _rpn(copy._rpn)
{}

RPN::~RPN()
{}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_rpn = other._rpn;

	return *this;
}

int	RPN::_result(int a, int b, char op) const
{
	switch (op)
	{
	case '+': return (a + b);
	case '-': return (a - b);
	case '*': return (a * b);
	case '/':
		if (b == 0)
			throw std::runtime_error("Error: impossible division by zero");
		return (a / b);
		
	default:
		throw std::runtime_error("unknow operator");
	}
}


void RPN::evaluate(const std::string &expression)
{
	size_t 	i = 0;
	int 	num = 0;
	char	c;
	
	while (i < expression.length())
	{
		c = expression[i];
		
		if (c == ' ')
		{
			i++;
			continue;
		}
		
		if (c >= '0' && c <= '9')
		{
			num = c - '0';
			_rpn.push(num);
			i++;
			continue;
		}
		
		if ((c == '+' || c == '*' || c == '-' || c == '/'))
		{
			if (_rpn.size() < 2)
				throw std::runtime_error("Error: insufficient operands");
			
			int b = _rpn.top(); _rpn.pop();
			int a = _rpn.top(); _rpn.pop();
			int RESULT = _result(a, b, c);
			
			_rpn.push(RESULT);

			i++;
			continue;
		}

		throw std::runtime_error("Error: Invalid token!");
	}
	
	if (_rpn.size() != 1) //il y avait des "choses" en plus
		throw std::runtime_error("Error: Invalid expression!");

	std::cout << _rpn.top() << std::endl;
}