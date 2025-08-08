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
#include <algorithm>
#include "utils.hpp"

class VecMerge
{
	private:
		// Private Attributes
		std::vector<int>							_nbrVec;
		int											_recLvl;
		std::chrono::_V2::system_clock::time_point	_startTime;
		
		std::vector<int>				fordJohnsonVec(std::vector<int> groups);
		void							insertPendIntoMain(std::vector<int>& mainChain, \
										const std::vector<int>& pend);

		
		public:
		// Constructors and Destructors
		VecMerge(void) = delete;
		VecMerge(char **argv, int argc);
		VecMerge(const VecMerge &rhs) = delete;
		VecMerge &operator=(const VecMerge &rhs) = delete;
		~VecMerge(void) = default;
		
		// Public Methods
		void	sort();
		void	printPairs();

} ;
