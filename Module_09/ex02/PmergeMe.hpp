#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <iterator>
#include <utility>

class PmergeMe
{
	private:
		struct PairData
		{
			int	small;
			int	big;

			PairData() : small(0), big(0) {}
			PairData(int s, int b) : small(s), big(b) {}
		};

		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	parseInput(char **av);
		bool	isPositiveInteger(const std::string &str) const;
		std::vector<std::size_t>	buildJacobsthalOrder(std::size_t n) const;

		template <typename Container>
		void	printContainer(const Container &c) const;

		template <typename Container>
		Container	mergeInsertSort(const Container &input) const;

		template <typename Container>
		std::vector<PairData>	makePairs(const Container &input, bool &hasStraggler, int &straggler) const;

		std::vector<PairData>	sortPairsByBig(const std::vector<PairData> &pairs) const;

		template <typename Container>
		Container	extractBigs(const std::vector<PairData> &pairs) const;

		template <typename Container>
		Container	buildMainChain(const std::vector<PairData> &sortedPairs) const;

		template <typename Container>
		typename Container::iterator	findNthValue(Container &chain, int value, std::size_t occurrence) const;

		template <typename Container>
		void	insertPendElements(Container &chain, const std::vector<PairData> &sortedPairs,
				const std::vector<std::size_t> &order) const;

		template <typename Container>
		void	insertStraggler(Container &chain, int straggler) const;

	public:
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	process() const;
};

#include "PmergeMe.tpp"

#endif