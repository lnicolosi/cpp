#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
	parseInput(av);
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vector(other._vector), _deque(other._deque)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool	PmergeMe::isPositiveInteger(const std::string &str) const
{
	if (str.empty())
		return false;
	for (std::size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PmergeMe::parseInput(char **av)
{
	for (int i = 1; av[i]; ++i)
	{
		std::string			arg(av[i]);
		std::istringstream	iss(arg);
		long				value;

		if (!isPositiveInteger(arg))
			throw std::runtime_error("Error");

		iss >> value;
		if (iss.fail() || !iss.eof() || value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");

		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
	if (_vector.empty())
		throw std::runtime_error("Error");
}

std::vector<PmergeMe::PairData>	PmergeMe::sortPairsByBig(const std::vector<PairData> &pairs) const
{
	if (pairs.size() <= 1)
		return pairs;

	std::vector<int> bigs;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		bigs.push_back(pairs[i].big);

	bigs = mergeInsertSort(bigs);

	std::vector<PairData>	sortedPairs;
	std::vector<bool>		used(pairs.size(), false);

	for (std::size_t i = 0; i < bigs.size(); ++i)
	{
		for (std::size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].big == bigs[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}
	return sortedPairs;
}

std::vector<std::size_t>	PmergeMe::buildJacobsthalOrder(std::size_t n) const
{
	std::vector<std::size_t>	order;
	if (n <= 1)
		return order;

	std::vector<std::size_t>	jacob;
	std::vector<bool>			used(n, false);

	jacob.push_back(0);
	jacob.push_back(1);

	while (jacob.back() < n)
	{
		std::size_t last = jacob[jacob.size() - 1];
		std::size_t prev = jacob[jacob.size() - 2];
		jacob.push_back(last + 2 * prev);
	}

	used[0] = true;

	for (std::size_t i = 2; i < jacob.size(); ++i)
	{
		std::size_t start = jacob[i - 1] + 1;
		std::size_t end = jacob[i];

		if (start >= n)
			break;
		if (end >= n)
			end = n - 1;

		for (std::size_t j = end + 1; j > start; --j)
		{
			std::size_t idx = j - 1;
			if (!used[idx])
			{
				order.push_back(idx);
				used[idx] = true;
			}
		}
	}

	for (std::size_t i = 1; i < n; ++i)
	{
		if (!used[i])
			order.push_back(i);
	}
	return order;
}

void	PmergeMe::process() const
{
	std::cout << "Before: ";
	printContainer(_vector);

	clock_t startVec = clock();
	std::vector<int> sortedVector = mergeInsertSort(_vector);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	std::deque<int> sortedDeque = mergeInsertSort(_deque);
	clock_t endDeq = clock();

	(void)sortedDeque;

	std::cout << "After:  ";
	printContainer(sortedVector);

	double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
	double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque  : " << deqTime << " us" << std::endl;
}