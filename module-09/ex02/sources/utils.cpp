#include "utils.hpp"


// Jacobsthal is a sequence similar to fibonacci, its 0, 1 and then every step the last number gets added
// and the second last multiplied by 2
// 0, 1, 1, 3, 5, 11, 21, 43 etc.
//it coincides with the best order of inserting the pend, we will just insert the indecies inbetween
// so after eleven u would add 10 to 6 after 21 20 to 12 etc.
//we use the same method to fill in the last bit between the final jacobs and n
std::vector<int> createJacobSeq(int n)
{
	std::vector<int> jacobSeq;
	int j0 = 0, j1 = 1, j2;
	while (true)
	{
		j2 = j1 + (2 * j0);
		if (j2 > n)
			break;
		jacobSeq.push_back(j2);
		for (int i = j2 - 1; i > j1 && i <= n; i--)
			jacobSeq.push_back(i);
		j0 = j1;
		j1 = j2;
	}
	for (int i = n; i > j1; i--)
	{
		jacobSeq.push_back(i);
	}

	// std::cout << "JACOB_SEQ --> ";
	// for (size_t i = 0; i < jacobSeq.size(); i++)
	// {
	// 	std::cout << jacobSeq[i] << " ";
	// }
	// std::cout << std::endl;
	return (jacobSeq);
}

void	printVec(std::string prefix, std::vector<int> &vec)
{
	std::cout << prefix;
	for (int nbr : vec)
		std::cout << nbr << " ";
}