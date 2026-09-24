#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> 		_vector;
		std::deque<int>			_deque;

		std::vector<int> 		_original;

		double 					_timeVector;
		double					_timedeque;

		//DEQUE
		void	_FordJohnsonDeque	(std::deque<int> &deque, int left, int right);
		void	_insertionSortDeque	(std::deque<int> &deque, int left, int right);
		void	_mergeSortDeque		(std::deque<int> &deque, int left, int midle, int right);
		//VECTOR
		void	_FordJohnsonVector	(std::vector<int> &vec, int left, int right);
		void	_insertionSortVector(std::vector<int> &vec, int left, int right);
		void	_mergeSortVector	(std::vector<int> &vec, int left, int midle, int right);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);

		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);

		bool 	parseInput(int ac, char **av);
		void	sort();
		void	printResult() const;
};


#endif //PMERGEME_HPP
