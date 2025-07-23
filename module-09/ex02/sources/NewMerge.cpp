#include "NewMerge.hpp"



// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

NewMerge::NewMerge(char **argv, int argc)
{
	int	curNbr;
	if (argc < 3)
			throw(std::invalid_argument("Can't sort without at least 2 numbers"));

	for (size_t i = 1; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); //should throw if out of range
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		_nbrVec.push_back(curNbr);		
	}
}

NewMerge::~NewMerge(void)
{
	std::cout << RED << "NewMerge: Destructor called" << RESET << std::endl;
}


// ************************************************************************** //
//                                private methods                              //
// ************************************************************************** //


void	NewMerge::makeFirstPairs()
{
	//what about dupes?
	int	nbr;
	for (size_t i = 0; i < _nbrVec.size(); i++)
	{
		nbr = _nbrVec.at(i);
		if (i % 2 == 0)
			_pairs.emplace_back(nbr);
		else
		{
			auto curstack = _pairs.back();
			curstack.push(nbr);
			if (curstack.front() > curstack.back())
			curstack.swap()
		}
	}
	if (_nbrVec.size() % 2 == 1) //if uneven, throw last nbr in pair by itself and make other -1
	{
		current.second = -1;
		_pairs.push_back(current);
	}

	
	//make sure first in pair is biggest
	for (auto& pair : _pairs)
	{
		if (pair.second > pair.first && pair.second != -1)
			std::swap(pair.first, pair.second);
	}
	//can i make this recursive? maybe with template function
	//make every pair a stack? would make recurse work and easy to split down middle latermake every pair a stack? would make recurse work and easy to split down middle later
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //


// INSERT SORT

// 1 MAKE PAIRS (biggest on top)

// 2 START UR BIG GROUP
// 	every split check het bovenste nummer (top of stack) van de lagere helft 


// 	(de bovenste helft gaat sws naar rechts/hoger want dat weet je al door het vormen van de paren) 



// lage deel van pair gaat altijd links van de stack waaar die uitkomt)


// CHECK ALLEEN TOP OF STACK


// (hoogste en laagste stacks weet je altijd al)


// gedurende did check of leftover stacks zelfde size zijn om ze in te voegen