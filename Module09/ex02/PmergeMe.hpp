#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <algorithm>
#include <cmath>
#include <set>

class PmergeMe
{
private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;
	double _vectorTime;
	double _dequeTime;

	// FJ AVEC VECT
	void mergeInsertSortVector(std::vector<int>& arr);
	void sortPairsVector(std::vector<std::pair<int, int> >& pairs);
	std::vector<int> generateJacobsthalSequence(size_t n);
	void insertInSortedVector(std::vector<int>& sorted, int value);

	// FJ AVEC DQ
	void mergeInsertSortDeque(std::deque<int>& arr);
	void sortPairsDeque(std::deque<std::pair<int, int> >& pairs);
	void insertInSortedDeque(std::deque<int>& sorted, int value);

	bool parseInput(int argc, char **argv);
	double getTime();

public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	bool run(int argc, char **argv);
	void displayResults();
};

#endif
