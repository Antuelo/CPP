#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <exception>
#include <string>


class RPN
{
	private:
		std::stack<int>		_rpn;

		int							_result		(int a, int b, char op) const;

	public:
		RPN();
		RPN(const RPN &copy);

		~RPN();

		RPN& operator=(const RPN &other);

		void	evaluate(const std::string& expression);
};

#endif