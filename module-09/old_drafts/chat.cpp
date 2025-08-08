#include <vector>
#include <iostream>
#include <algorithm>

void	insertPendIntoMain(std::vector<std::vector<int>>& main, \
	std::vector<std::vector<int>>& pend);


std::vector<std::vector<int>>	recursiveFordJohnson(std::vector<std::vector<int>> groups);

 std::vector<int>	generateJacobsthal(int n)
{
	 std::vector<int>	_jacobseq;
	int j0 = 0, j1 = 1;


	_jacobseq.push_back(0);
	while (true)
	{
		int j2 = j1 + (2 * j0);
		if (j2 > n)
			break;

		_jacobseq.push_back(j2);
		
		//add all indices inbetween
		for (int i = j2 - 1; i > j1 && i <= n; i--)
			_jacobseq.push_back(i);

		j0 = j1;
		j1 = j2;
	}

	//fill in last indices between last jacobs and n
	for (int i = n; i > j1; i--)
	{
		_jacobseq.push_back(i);
	}

	std::cout << "JACOB_SEQ --> ";

	for (size_t i = 0; i < _jacobseq.size(); i++)
	{
		std::cout << _jacobseq[i] << " ";
	}
	std::cout << std::endl;
	return (_jacobseq);
}

void	sort(char **argv)
{
	int curNbr;
	std::vector<std::vector<int>> groups;
	for (size_t i = 1; argv[i]; i++)
	{
		curNbr = std::stoi(argv[i]); //should throw if out of range
		if (curNbr < 0)
			throw (std::invalid_argument("no negative ints allowed"));
		groups.push_back(std::vector<int>{curNbr});
	}
    
    // Use TRUE recursive Ford-Johnson
    std::vector<std::vector<int>> sortedResult = recursiveFordJohnson(groups);
    
    std::vector<int> _nbrVec;
    for (const auto& group : sortedResult) {
        for (int num : group) {
            _nbrVec.push_back(num);
			std::cout << num << " ";
        }
    }
}

std::vector<std::vector<int>>	recursiveFordJohnson(std::vector<std::vector<int>> groups)
{
    // Base case
    if (groups.size() <= 1) return groups;
    
    std::cout << "Processing level with " << groups.size() << " groups" << std::endl;
    
    // 1. Pair up and create main/pend
    std::vector<std::vector<int>> main;    // Winners
    std::vector<std::vector<int>> pend;    // Losers to insert
    
    // for (size_t i = 0; i + 1 < groups.size(); i += 2) {
    //     auto group1 = groups[i];
    //     auto group2 = groups[i + 1];
        
    //     // Compare representatives
    //     if (group1[0] < group2[0]) {
    //         std::swap(group1, group2);
    //     }
        
    //     // Winner: merge both groups (winner's elements first)
    //     std::vector<int>	winner;
    //     winner.insert(winner.end(), group1.begin(), group1.end());
	// 	winner.insert(winner.end(), group2.begin(), group2.end());
        
    //     main.push_back(winner);
    //     pend.push_back(group2); // The loser goes to pend
    // }

	  for (size_t i = 0; i + 1 < groups.size(); i += 2) {
        auto group1 = groups[i];
        auto group2 = groups[i + 1];
        
        // Determine winner and loser
        if (group1[0] < group2[0]) {
            main.push_back(group2);  // Winner to main
            pend.push_back(group1);  // Loser to pend
        } else {
            main.push_back(group1);  // Winner to main
            pend.push_back(group2);  // Loser to pend
        }
    }
    
    // Handle odd group
    if (groups.size() % 2 == 1) {
        pend.push_back(groups.back());
    }
    
    // 2. Recursively sort the main chain
    std::vector<std::vector<int>> sortedMain = recursiveFordJohnson(main);
    
    // 3. Insert pend into sorted main using Jacobsthal
    insertPendIntoMain(sortedMain, pend);
    
    return sortedMain;
}

void	insertPendIntoMain(std::vector<std::vector<int>>& main, 
                                  std::vector<std::vector<int>>& pend)
{
    if (pend.empty()) return;
    
    // Generate Jacobsthal for this level
    std::vector<int> jacobSeq = generateJacobsthal(pend.size());
    
    for (int index : jacobSeq) {
        if (index > 0 && index <= (int)pend.size()) {
            auto& groupToInsert = pend[index - 1];
            
            // Binary search for insertion position
            int representative = groupToInsert[0];
			size_t insertPos = 0;
            for (size_t i = 0; i < main.size(); i++) {
                if (!main[i].empty() && main[i][0] > representative) {
                    insertPos = i;
                    break;
                }
                insertPos = i + 1;
            }	
            
            main.insert(main.begin() + insertPos, groupToInsert);
        }
    }
}