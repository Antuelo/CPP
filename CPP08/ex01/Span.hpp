#ifndef SPAN_CPP
#define SPAN_CPP

#include <iostream>
#include <exception>
#include <vector>

class Span
{
	private:
		std::vector<unsigned int> vec;

	public:
		void			addnumber(unsigned int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
};


#endif //SPAN_CPP
