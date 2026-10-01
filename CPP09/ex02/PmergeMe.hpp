#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <utility>
#include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int> 		_vector;
		std::deque<int>			_deque;

		std::vector<int> 		_original;

		double 					_timeVector;
		double					_timeDeque;

		//DEQUE
		void	_insertionSortDeque			(std::deque<int> &deque, int left, int right);
		void	_makepairDeque				(std::deque<int> &deque, int left, int right, std::deque<std::pair<int, int> > &pairs, int &straggler);
		void	_sortPairsRecursivelyDeque	(std::deque<std::pair<int,int> > &pairs);
		void	_buildResultDeque			(std::deque<std::pair<int,int> > &pairs, std::deque<int> &result);
		void	_insertWithJacobsthalDeque	(std::deque<std::pair<int,int> > &pairs, std::deque<int> &result);
		void	_insertStragglerDeque		(std::deque<int> &result, int straggler);
		void	_FordJohnsonDeque			(std::deque<int> &deque, int left, int right);
		//VECTOR
		void	_insertionSortVector		(std::vector<int> &vec, int left, int right);
		void	_makepairVector 			(std::vector<int> &vec, int left, int right, std::vector<std::pair<int, int> > &pairs, int &straggler);
		void 	_sortPairsRecursivelyVector	(std::vector<std::pair<int,int> > &pairs);
		void	_buildResultVector			(std::vector<std::pair<int,int> > &pairs, std::vector<int> &result);
		void	_insertWithJacobsthalVector	(std::vector<std::pair<int,int> > &pairs, std::vector<int> &result);
		void	_insertStragglerVector		(std::vector<int> &result, int straggler);
		void	_FordJohnsonVector			(std::vector<int> &vec, int left, int right);

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
