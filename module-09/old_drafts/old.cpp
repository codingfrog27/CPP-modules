

void	NewMerge::printPairs()
{
	std::cout << "PAIRS ARE: --> " << std::endl;
	for (size_t i = 0; i < _pairs.size(); i++)
	{
		std::cout << "[";
		for (size_t j = 0; j < _pairs[i].size(); ++j) {
			std::cout << _pairs[i][j];
			if (j + 1 < _pairs[i].size())
				std::cout << ", ";
		}
		std::cout << "]" << std::endl;
	}
}

//keeps merging the groups untill no size doubling is possible anymore
std::vector<std::vector<int>> NewMerge::groupPairs(std::vector<std::vector<int>> groups)
{
	size_t i = 0, next = 1, groupSize = groups.size();

	if (groupSize <= 1 || groupSize != groups[1].size())
		return groups;

	while (groups.size() > 1)
	{
		// if (next > _nbrVec.size() || next > _pairs.size() ||  _pairs[next].size() != groupSize)
		if (next >= groups.size() || groups[next].size() != groupSize)
			break; //split this if too see if can be simplified and exit condition can be improved! :)
		if (groups[i][0] < groups[next][0])
			std::swap(groups[i], groups[next]);
		groups[i].insert(groups[i].end(), groups[next].begin(), groups[next].end());
		groups.erase(groups.begin() + next);		
		i++;
		next++;
	}
	//remove trailing nbr if its there
	if (i < _nbrVec.size() && _nbrVec.size() > 1)
		_nbrVec.erase(_nbrVec.begin() + i);
	

		
	//keep going untill no doubling is possible anymore 
	// if (_pairs.front().size() == _pairs.at(next).size())
	if (groups.front().size() != groupSize)
	{
		// std::cout << "new groupsize == " << _pairs.front().size() << " old size == " << groupSize << "\ngrouping again" << std::endl;
		printPairs();
		groupPairs(groups);
	}
	else
		std::cout << "amogus" << std::endl;
	return groups;
}

// The main is initialised with the elements {b1, a1} and then with the rest of a's.
// The pend is initialised with the rest of bs starting from b2.
void	NewMerge::binaryInsert()
{
	size_t	i = 0, next = 1, groupAmount = 0, groupSize = _pairs[0].size(), halfSize = groupSize / 2;
	std::vector<int> currentGroup;
	while (!_pairs.empty())
	{
		while (groupAmount < _pairs.size() && groupSize == _pairs[groupAmount].size())
			groupAmount++;

			
			currentGroup.insert(_pairs[next].begin(), _pairs[next].end());
			_pairs.erase(_pairs.begin() + next);
			_pairs.insert(_pairs.begin() + i, currentGroup);
	}
}


// std::vector<std::vector<int>> NewMerge::groupPairs(std::vector<std::vector<int>> groups)
// {
// 	size_t i = 0, next = 1, groupSize = _pairs[i].size();
// 	while (_nbrVec.size() > 1)
// 	{
// 		if (next > _nbrVec.size() || next > _pairs.size() ||  _pairs[next].size() != groupSize)
// 			break; //split this if too see if can be simplified and exit condition can be improved! :)

// 		if (_nbrVec[i] < _nbrVec[next])
// 		{
// 			std::swap(_nbrVec[i], _nbrVec[next]);
// 			std::swap(_pairs[i], _pairs[next]);
// 		}

// 		_pairs[i].insert(_pairs[i].end(), _pairs[next].begin(), _pairs[next].end());
// 		_pairs.erase(_pairs.begin() + next);
		
// 		//main chain will only have the winners (up to only the largest number) so others get removed
// 		// (This also will keep it the index in line with pairs) :)
// 		_nbrVec.erase(_nbrVec.begin() + next);
// 		i++;
// 		next++;
// 	}
// 	//remove trailing nbr if its there
// 	if (i < _nbrVec.size() && _nbrVec.size() > 1)
// 		_nbrVec.erase(_nbrVec.begin() + i);
	

		
	
// 	//keep going untill no doubling is possible anymore 
// 	// if (_pairs.front().size() == _pairs.at(next).size())
// 	if (_pairs.front().size() != groupSize)
// 	{
// 		// std::cout << "new groupsize == " << _pairs.front().size() << " old size == " << groupSize << "\ngrouping again" << std::endl;
// 		printPairs();
// 		groupPairs();
// 	}
// 	else
// 		std::cout << "amogus" << std::endl;
// }