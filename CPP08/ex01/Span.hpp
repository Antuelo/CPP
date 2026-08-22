#ifndef SPAN_CPP
#define SPAN_CPP

#include <algorithm>
#include <iostream>
#include <exception>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <climits>


class Span
{
	private:
		std::vector<unsigned int> 	_vec;
		unsigned int				_max_size;

	public:
		Span(unsigned int N);
		Span();
		Span(const Span &copy);

		~Span();

		Span &operator=(const Span &other);
		
		class unsifficentNumbers : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "Error: We need a least 2 numbers to calculate Span!";}
		};

		class NotMoreSpace : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "Error: Span is full";}
		};

		class invalidNumbers : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "The numbers isn't valid, retry again";}
		};

		void			addNumber(unsigned int num);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			print_vec() const;
		void			print_sorted_vec() const;

		std::vector<unsigned int>::iterator begin()	{return _vec.begin();};
		std::vector<unsigned int>::iterator end()	{return _vec.end();};
		
		template <typename iter>
		void			addRange(iter begin, iter end)
		{
			if (end == begin)
				throw invalidNumbers();

			unsigned int dist 				= std::distance(begin,end);
			unsigned int available_space 	= _max_size - _vec.size();

			if (dist > available_space)
				throw NotMoreSpace();

			for (iter it = begin; it != end; it++)
				_vec.push_back(*it);
		};
};


#endif //SPAN_CPP
