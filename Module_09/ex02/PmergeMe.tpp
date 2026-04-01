#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template <typename Container>
void	PmergeMe::printContainer(const Container &c) const
{
	typename Container::const_iterator	it = c.begin();
	typename Container::const_iterator	end = c.end();

	for (; it != end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename Container>
std::vector<PmergeMe::PairData>	PmergeMe::makePairs(const Container &input, bool &hasStraggler, int &straggler) const
{
	std::vector<PairData> pairs;
	typename Container::const_iterator	it = input.begin();

	hasStraggler = false;
	straggler = 0;

	while (it != input.end())
	{
		int first = *it;
		++it;
		if (it == input.end())
		{
			hasStraggler = true;
			straggler = first;
			break;
		}
		int second = *it;
		++it;
		if (first <= second)
			pairs.push_back(PairData(first, second));
		else
			pairs.push_back(PairData(second, first));
	}
	return pairs;
}

template <typename Container>
Container	PmergeMe::extractBigs(const std::vector<PairData> &pairs) const
{
	Container result;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		result.push_back(pairs[i].big);
	return result;
}

template <typename Container>
Container	PmergeMe::buildMainChain(const std::vector<PairData> &sortedPairs) const
{
	Container chain;

	if (sortedPairs.empty())
		return chain;

	chain.push_back(sortedPairs[0].small);
	chain.push_back(sortedPairs[0].big);

	for (std::size_t i = 1; i < sortedPairs.size(); ++i)
		chain.push_back(sortedPairs[i].big);

	return chain;
}

template <typename Container>
typename Container::iterator	PmergeMe::findNthValue(Container &chain, int value, std::size_t occurrence) const
{
	typename Container::iterator	it = chain.begin();
	typename Container::iterator	end = chain.end();
	std::size_t					count = 0;

	for (; it != end; ++it)
	{
		if (*it == value)
		{
			if (count == occurrence)
				return it;
			++count;
		}
	}
	return chain.end();
}

template <typename Container>
void	PmergeMe::insertPendElements(Container &chain, const std::vector<PairData> &sortedPairs, const std::vector<std::size_t> &order) const
{
	for (std::size_t k = 0; k < order.size(); ++k)
	{
		std::size_t idx = order[k];
		if (idx == 0 || idx >= sortedPairs.size())
			continue;

		int small = sortedPairs[idx].small;
		int big = sortedPairs[idx].big;

		std::size_t sameBigBefore = 0;
		for (std::size_t i = 0; i < idx; ++i)
		{
			if (sortedPairs[i].big == big)
				++sameBigBefore;
		}

		typename Container::iterator partnerPos = findNthValue(chain, big, sameBigBefore);
		typename Container::iterator insertPos;

		if (partnerPos == chain.end())
			insertPos = std::lower_bound(chain.begin(), chain.end(), small);
		else
			insertPos = std::lower_bound(chain.begin(), partnerPos, small);

		chain.insert(insertPos, small);
	}
}

template <typename Container>
void	PmergeMe::insertStraggler(Container &chain, int straggler) const
{
	typename Container::iterator	pos;

	pos = std::lower_bound(chain.begin(), chain.end(), straggler);
	chain.insert(pos, straggler);
}

template <typename Container>
Container	PmergeMe::mergeInsertSort(const Container &input) const
{
	if (input.size() <= 1)
		return input;

	bool					hasStraggler;
	int						straggler;
	std::vector<PairData>	pairs = makePairs(input, hasStraggler, straggler);

	if (pairs.empty())
	{
		Container result;
		if (hasStraggler)
			result.push_back(straggler);
		return result;
	}

	std::vector<PairData>	sortedPairs = sortPairsByBig(pairs);
	Container				chain = buildMainChain<Container>(sortedPairs);
	std::vector<std::size_t> order = buildJacobsthalOrder(sortedPairs.size());

	insertPendElements(chain, sortedPairs, order);

	if (hasStraggler)
		insertStraggler(chain, straggler);

	return chain;
}

#endif