#pragma once


#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"


#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <exception>
#include <chrono>
#include "utils.hpp"


class QueMerge
{
	private:
		// Private Attributes

		std::deque<int>								_nbrQue;
		int											_recLvl;
		std::chrono::_V2::system_clock::time_point	_startTime;

		std::deque<int>	fordJohnsonVec(std::deque<int> groups);
		void			insertPendIntoMain(std::deque<int>& mainChain, \
										const std::deque<int>& pend);

		
		public:
		// Constructors and Destructors
		QueMerge(void) = delete;
		QueMerge(char **argv, int argc);
		QueMerge(const QueMerge &rhs) = delete;
		QueMerge &operator=(const QueMerge &rhs) = delete;
		~QueMerge(void) = default;
		
		// Public Methods
		void	sort();
		void	printPairs();

} ;
