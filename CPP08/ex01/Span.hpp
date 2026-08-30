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
		std::vector<int>			_vec;
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
				virtual const char* what() const throw() {return "The space number isn't valid";}
		};

		int		shortestSpan();
		int		longestSpan();
		void	addNumber(int num);
		
		void	print_vec() 		const;
		void	print_sorted_vec() 	const;

		std::vector<int>::iterator begin()	{return _vec.begin();};
		std::vector<int>::iterator end()	{return _vec.end();};
		
		template <typename iter>
		void			addRange(iter begin, iter end)
		{
			if (end == begin)
				throw invalidNumbers();

			std::size_t		dist 				= std::distance(begin,end);
			std::size_t		available_space 	= _max_size - _vec.size();

			if (dist > available_space)
				throw NotMoreSpace();

			for (iter it = begin; it != end; it++)
				_vec.push_back(*it);
		};
};


#endif //SPAN_CPP
