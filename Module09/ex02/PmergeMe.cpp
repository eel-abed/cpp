#include "PmergeMe.hpp"
#include <limits>
#include <stdexcept>
#include <iomanip>

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
		_vectorTime = other._vectorTime;
		_dequeTime = other._dequeTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

double PmergeMe::getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

bool PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided" << std::endl;
		return false;
	}

	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];

		if (arg.empty())
		{
			std::cerr << "Error" << std::endl;
			return false;
		}

		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << "Error" << std::endl;
				return false;
			}
		}

		std::istringstream iss(arg);
		long num;
		iss >> num;

		if (iss.fail() || num < 0 || num > std::numeric_limits<int>::max())
		{
			std::cerr << "Error" << std::endl;
			return false;
		}

		_vectorData.push_back(static_cast<int>(num));
		_dequeData.push_back(static_cast<int>(num));
	}

	std::set<int> uniqueValues(_vectorData.begin(), _vectorData.end());
	if (uniqueValues.size() != _vectorData.size())
	{
		std::cerr << "Error" << std::endl;
		return false;
	}

	return true;
}

std::vector<int> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<int> jacobsthal;
	if (n == 0)
		return jacobsthal;

	jacobsthal.push_back(0);
	if (n == 1)
		return jacobsthal;

	jacobsthal.push_back(1);

	while (true)
	{
		size_t size = jacobsthal.size();
		int next = jacobsthal[size - 1] + 2 * jacobsthal[size - 2];
		if (static_cast<size_t>(next) >= n)
			break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

void PmergeMe::insertInSortedVector(std::vector<int> &sorted, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

void PmergeMe::sortPairsVector(std::vector<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
	}
	//impair
	int straggler = -1;
	bool hasStraggler = false;
	if (i < arr.size())
	{
		straggler = arr[i];
		hasStraggler = true;
	}

	sortPairsVector(pairs);
	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t j = 0; j < pairs.size(); j++)
	{
		mainChain.push_back(pairs[j].first);
		pending.push_back(pairs[j].second);
	}

	if (!pending.empty())
	{
		mainChain.insert(mainChain.begin(), pending[0]);
		pending.erase(pending.begin());
	}

	std::vector<int> jacobsthal = generateJacobsthalSequence(pending.size() + 1);
	std::vector<bool> inserted(pending.size(), false);
	for (size_t j = 2; j < jacobsthal.size(); j++)
	{
		int currentJacob = jacobsthal[j];
		int prevJacob = jacobsthal[j - 1];

		for (int k = std::min(currentJacob, static_cast<int>(pending.size())) - 1;
			 k >= prevJacob && k >= 0; k--)
		{
			if (!inserted[k])
			{
				insertInSortedVector(mainChain, pending[k]);
				inserted[k] = true;
			}
		}
	}
	for (size_t j = 0; j < pending.size(); j++)
	{
		if (!inserted[j])
			insertInSortedVector(mainChain, pending[j]);
	}

	if (hasStraggler)
		insertInSortedVector(mainChain, straggler);

	arr = mainChain;
}

void PmergeMe::insertInSortedDeque(std::deque<int> &sorted, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(pos, value);
}

void PmergeMe::sortPairsDeque(std::deque<std::pair<int, int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}

	for (size_t i = 0; i < pairs.size(); i++)
	{
		for (size_t j = i + 1; j < pairs.size(); j++)
		{
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	size_t i;
	for (i = 0; i + 1 < arr.size(); i += 2)
	{
		pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
	}
	//impair
	int straggler = -1;
	bool hasStraggler = false;
	if (i < arr.size())
	{
		straggler = arr[i];
		hasStraggler = true;
	}
	sortPairsDeque(pairs);
	std::deque<int> mainChain;
	std::deque<int> pending;
	for (size_t j = 0; j < pairs.size(); j++)
	{
		mainChain.push_back(pairs[j].first);
		pending.push_back(pairs[j].second);
	}

	if (!pending.empty())
	{
		mainChain.push_front(pending[0]);
		pending.erase(pending.begin());
	}




	//js
	std::vector<int> jacobsthal = generateJacobsthalSequence(pending.size() + 1);
	std::vector<bool> inserted(pending.size(), false);

	for (size_t j = 2; j < jacobsthal.size(); j++)
	{
		int currentJacob = jacobsthal[j];
		int prevJacob = jacobsthal[j - 1];

		for (int k = std::min(currentJacob, static_cast<int>(pending.size())) - 1;
			 k >= prevJacob && k >= 0; k--)
		{
			if (!inserted[k])
			{
				insertInSortedDeque(mainChain, pending[k]);
				inserted[k] = true;
			}
		}
	}
	for (size_t j = 0; j < pending.size(); j++)
	{
		if (!inserted[j])
			insertInSortedDeque(mainChain, pending[j]);
	}
	if (hasStraggler)
		insertInSortedDeque(mainChain, straggler);

	arr = mainChain;
}

bool PmergeMe::run(int argc, char **argv)
{
	if (!parseInput(argc, argv))
		return false;

	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorData.size(); i++)
	{
		std::cout << _vectorData[i];
		if (i < _vectorData.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	std::vector<int> vectorCopy = _vectorData;
	double startTime = getTime();
	mergeInsertSortVector(vectorCopy);
	double endTime = getTime();
	_vectorTime = endTime - startTime;

	std::deque<int> dequeCopy = _dequeData;
	startTime = getTime();
	mergeInsertSortDeque(dequeCopy);
	endTime = getTime();
	_dequeTime = endTime - startTime;

	std::cout << "After:  ";
	for (size_t i = 0; i < vectorCopy.size(); i++)
	{
		std::cout << vectorCopy[i];
		if (i < vectorCopy.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size()
			  << " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size()
			  << " elements with std::deque : " << _dequeTime << " us" << std::endl;

	return true;
}

void PmergeMe::displayResults()
{
}
