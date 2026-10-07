/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antuel <antuel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 13:17:43 by antuel            #+#    #+#             */
/*   Updated: 2026/10/07 21:48:41 by antuel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy):
	_vector(copy._vector),
	_deque(copy._deque)
{}

PmergeMe::~PmergeMe()
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque 	= other._deque;
	}

	return *this;
}



bool	PmergeMe::parseInput(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: need at least one number" << std::endl;
		return false;
	}
	
	long 	num = 0;
	
	for (int i = 1; i < ac; i++)
	{
		std::string 	str = av[i];
		if (str.empty())
		{
			std::cerr << "Error: empty argument" << std::endl;
			return false;
		}
				
		for (int j = 0; j < (int)str.length(); j++) // correction de chaque caractère
		{
			if (std::isdigit(static_cast<unsigned char>(str[j]))) //hago cast para las letras con tilde que pueden ser negativas = undefined behavior
				continue;
			
			if (str[j] == '-')
				std::cerr << "Error: Negative or null numbers are not allowed." << std::endl;
			else
				std::cerr << "Error: invalid character, only numbers are accepted" << std::endl;
			return false;
		}
		
		char *end;
		num = std::strtol(str.c_str(), &end, 10);
		if (*end != '\0')
		{
			std::cerr << "Error: converion strtol" << std::endl;
			return false;
		}
		if( num > 2147483647)
		{
			std::cerr << "Error: number too long" << std::endl;
			return false;
		}

		if (num <= 0)
		{
			std::cerr << "Error: Negative or null numbers are not allowed." << std::endl;
			return false;
		}

		_vector.push_back(num);
		_deque.push_back(num);
	}
	
	_original = _vector;
	return true;
}


void PmergeMe::sort()
{
	double		 time_startVector;
	double		 time_endVector;

	time_startVector = clock();
	_FordJohnsonVector(_vector, 0, (int)_vector.size() - 1);
	time_endVector	 = clock();

	_timeVector = (double(time_endVector - time_startVector)/ CLOCKS_PER_SEC * 1000);

	double 		time_startDeque;
	double 		time_endDeque;

	time_startDeque = clock();
	_FordJohnsonDeque(_deque, 0, (int)_deque.size() - 1);
	time_endDeque	= clock();

	_timeDeque = (double(time_endDeque - time_startDeque) / CLOCKS_PER_SEC * 1000);
}


void PmergeMe::printResult() const
{
	std::cout << "Before: ";
	for(size_t i = 0; i < _original.size(); i++)
		std::cout << _original[i] << " ";

	std::cout << std::endl;
	
	std::cout << "After: ";
	size_t i = 0;
	for (; i < _vector.size(); i++)
		std::cout << _vector[i] << " ";
	
	std::cout << "\n" << std::endl;
	
	std::cout << "Time to process a range of " << i <<" elements with std::vector : " << _timeVector << " us"<<std::endl;
	std::cout << "Time to process a range of " << i <<" elements with std::deque  : " << _timeDeque << " us" <<std::endl;
}


//------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------VECTOR--------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------


void PmergeMe::_insertionSortVector(std::vector<int> &vec, int left, int right)
{
	int		key = 0;
	int 	j 	= 0;

	for (int i = left + 1; i <= right; i++)
	{
		key = vec[i];
		j 	= i - 1;

		while (j >= left && vec[j] > key)
		{
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

//doing vector and range inside pair
void PmergeMe::_makepairVector(std::vector<int> &vec, int left, int right, std::vector<std::pair<int, int> > &pairs, int &straggler)
{
	int i = left;
	
	while (i + 1 <= right)
	{
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		
		i += 2;
	}

	if (i <= right)
		straggler = vec[i];
	else
		straggler = -1;
}


//j ordene des pairs a partir du plus grans (second)
void PmergeMe::_sortPairsRecursivelyVector(std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> A;
	for (size_t k = 0; k < pairs.size(); k++)
		A.push_back(pairs[k].second);

	if (A.size() > 1)
		_FordJohnsonVector(A, 0, A.size() - 1);

	std::vector<std::pair<int,int> > sorted;
	std::vector<bool> used(pairs.size(), false);// control de numeros duplicados
	
	for (size_t k = 0; k < A.size(); k++)
	{
		for(size_t l = 0; l < pairs.size(); l++)
		{
			if (!used[l] && pairs[l].second == A[k])
			{
				sorted.push_back(pairs[l]);
				used[l] = true;
				break;
			}
		}
	}
	pairs = sorted;
}

void PmergeMe::_buildResultVector(std::vector<std::pair<int,int> > &pairs, std::vector<int> &result)
{
	result.push_back(pairs[0].first);
	for(size_t i = 0; i < pairs.size(); i++)
		result.push_back(pairs[i].second);
}

void	PmergeMe::_insertWithJacobsthalVector(std::vector<std::pair<int,int> > &pairs, std::vector<int> &result)
{
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

	while (jacobsthal.back() < (int)pairs.size())
	{
		int n = jacobsthal.size();
		jacobsthal.push_back(jacobsthal[n-1] + 2*jacobsthal[n-2]);	//formule: J(n) = J(n-1) + 2*J(n-2) ... alors jacobsthal[n-1] c'est J(n-1), jacobsthal[n-2] c'est J(n-2)
	}    // Si pairs.size() = 12, jacobsthal queda [1, 3, 5, 11, 21].
	
	std::vector<bool> inserted(pairs.size(), false);
	inserted[0] = true;

	int		prev = 0;//prev c'est le groupe déjä procesé 
	
	for(size_t k = 0; k < jacobsthal.size(); k++)
	{
		int cur = jacobsthal[k];
		
		if (cur > (int)pairs.size() - 1)
			cur = pairs.size() - 1;

		for(int idx = cur; idx > prev; idx--)
		{
			if (idx < 0 || idx >= (int)pairs.size() || inserted[idx])
				continue;

			int B = pairs[idx].first;
			int A = pairs[idx].second;

			int limit = 0;

			for(size_t r = 0; r < result.size(); r++)
			{
				if (result[r] == A)
				{
					limit = r;
					break;
				}
			}
			
			int lo = 0;
			int hi = limit;
			while (lo < hi)
			{
				int mid = (lo + hi) /2;
				if (result[mid] < B)
					lo = mid + 1;
				else
					hi = mid;
			}
			
			result.insert(result.begin() + lo, B);

			inserted[idx] = true;
		}
		
		prev = cur;
	}
}


void PmergeMe::_insertStragglerVector(std::vector<int> &result, int straggler)
{
	if (straggler == -1)
		return;

	int lo = 0;
	int hi = (int)result.size();
	
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (result[mid] < straggler)
			lo = mid + 1;
		else
			hi = mid;
	}

	result.insert(result.begin() + lo, straggler);
}


void PmergeMe::_FordJohnsonVector(std::vector<int> &vec, int left, int right)
{
	int rangeSize = right - left + 1;
	
	if (rangeSize <= 16)
	{
		_insertionSortVector(vec, left, right);
		return;
	}

	std::vector<std::pair<int,int> > 	pairs;
	std::vector<int>					result;
	int 								straggler = -1;
	
	_makepairVector					(vec, left, right, pairs, straggler);
	_sortPairsRecursivelyVector		(pairs);
	_buildResultVector				(pairs, result);
	_insertWithJacobsthalVector		(pairs, result);
	_insertStragglerVector			(result, straggler);

	for(size_t i = 0; i < result.size(); i++)
		vec[i + left] = result[i];
}


//------------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------DEQUE---------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------

void PmergeMe::_insertionSortDeque(std::deque<int> &deque, int left, int right)
{
	int		key = 0;
	int		j 	= 0;
	
	for(int i = left + 1; i <= right; i++)
	{
		key = deque[i];
		j 	= i - 1;

		while (j >= left && deque[j] > key)
		{
			deque[j + 1] = deque[j];
			j--;
		}
		deque[j + 1] = key;
	}
}


void PmergeMe::_makepairDeque(std::deque<int> &deque, int left, int right, std::deque<std::pair<int, int> > &pairs, int &straggler)
{
	int i = left;
	
	while (i + 1 <= right)
	{
		if (deque[i] > deque[i + 1])
			std::swap(deque[i], deque[i + 1]);
		
		pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
		
		i += 2;
	}

	if (i <= right)
		straggler = deque[i];
	else
		straggler = -1;
}


void PmergeMe::_sortPairsRecursivelyDeque(std::deque<std::pair<int, int> > &pairs)
{
	std::deque<int> A;
	for (size_t k = 0; k < pairs.size(); k++)
		A.push_back(pairs[k].second);

	if (A.size() > 1)
		_FordJohnsonDeque(A, 0, A.size() - 1);

	std::deque<std::pair<int,int> > sorted;
	std::deque<bool> used(pairs.size(), false);
	
	for (size_t k = 0; k < A.size(); k++)
	{
		for(size_t l = 0; l < pairs.size(); l++)
		{
			if (!used[l] && pairs[l].second == A[k])
			{
				sorted.push_back(pairs[l]);
				used[l] = true;
				break;
			}
		}
	}
	pairs = sorted;
}


void PmergeMe::_buildResultDeque(std::deque<std::pair<int,int> > &pairs, std::deque<int> &result)
{
	result.push_back(pairs[0].first);
	for(size_t i = 0; i < pairs.size(); i++)
		result.push_back(pairs[i].second);
}


void	PmergeMe::_insertWithJacobsthalDeque(std::deque<std::pair<int,int> > &pairs, std::deque<int> &result)
{
	std::deque<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);

	while (jacobsthal.back() < (int)pairs.size())
	{
		int n = jacobsthal.size();
		jacobsthal.push_back(jacobsthal[n-1] + 2*jacobsthal[n-2]);
	}

	std::deque<bool> inserted(pairs.size(), false);
	inserted[0] = true;

	int		prev = 0;
	
	for(size_t k = 0; k < jacobsthal.size(); k++)
	{
		int cur = jacobsthal[k];
		
		if (cur > (int)pairs.size() - 1)
			cur = pairs.size() - 1;

		for(int idx = cur; idx > prev; idx--)
		{
			if (idx < 0 || idx >= (int)pairs.size() || inserted[idx])
				continue;

			int B = pairs[idx].first;
			int A = pairs[idx].second;

			int limit = 0;

			for(size_t r = 0; r < result.size(); r++)
			{
				if (result[r] == A)
				{
					limit = r;
					break;
				}
			}
			
			int lo = 0;
			int hi = limit;
			while (lo < hi)
			{
				int mid = (lo + hi) /2;
				if (result[mid] < B)
					lo = mid + 1;
				else
					hi = mid;
			}
			
			result.insert(result.begin() + lo, B);

			inserted[idx] = true;
		}
		
		prev = cur;
	}
}


void PmergeMe::_insertStragglerDeque(std::deque<int> &result, int straggler)
{
	if (straggler == -1)
		return;

	int lo = 0;
	int hi = (int)result.size();
	
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (result[mid] < straggler)
			lo = mid + 1;
		else
			hi = mid;
	}

	result.insert(result.begin() + lo, straggler);
}


void PmergeMe::_FordJohnsonDeque(std::deque<int> &deque, int left, int right)
{
	int rangeSize = right - left + 1;
	
	if (rangeSize <= 16)
	{
		_insertionSortDeque(deque, left, right);
		return;
	}

	std::deque<std::pair<int,int> >	pairs;
	std::deque<int>					result;
	int								straggler = -1;
	
	_makepairDeque					(deque, left, right, pairs, straggler);
	_sortPairsRecursivelyDeque		(pairs);
	_buildResultDeque				(pairs, result);
	_insertWithJacobsthalDeque		(pairs, result);
	_insertStragglerDeque			(result, straggler);

	for(size_t i = 0; i < deque.size(); i++)
		deque[i + left] = result[i];
}


/*
static const int jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
                              1365, 2731, 5461, 10923, 21845, 43691,
                              87381, 174763, 349525, 699051, 1398101,
                              2796203, 5592405, 11184811, 22369621,
                              44739243, 89478485, 178956971, 357913941,
                              715827883, 1431655765};
*/