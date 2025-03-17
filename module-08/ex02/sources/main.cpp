/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/03/17 14:25:35 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <ctime>

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define LINE "-----------------------------------------"


void	promptEnter()
{	
	std::cout << C_YELLOW "\nPress Enter to continue..." C_RESET << std::endl;
	std::cin.get();
}

int RandomNbr()
{
	static std::mt19937 generator(std::time(nullptr));
	static std::uniform_int_distribution<int> distribution(0, 100);
		
	return distribution(generator);
}


template <typename T, typename Container>
void	testMutantStack(MutantStack<T, Container> &mstack)
{
	for (size_t i = 0; i < 10; i++)
		mstack.push(RandomNbr());
	
	std::cout << C_CYAN "Before pop" C_RESET << std::endl;	
	std::cout << "Top element: " << mstack.top() << "  & Stack size: " << mstack.size() << std::endl;
	std::cout << "Stack contents: \n";
	for (typename MutantStack<T, Container>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	mstack.pop();
	std::cout << C_CYAN "\n\nafter pop\n" C_RESET << std::endl;	
	std::cout << "Top element: " << mstack.top() << "  & Stack size: " << mstack.size() << std::endl;
		
	std::cout << "Stack contents: \n";
	for (typename MutantStack<T, Container>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << C_CYAN "using reverse iterators\n" C_RESET"Stack contents: \n";
	for (auto it = mstack.rbegin(); it != mstack.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n" LINE << std::endl;
}


int main() {
	// Testing with default container (deque)
	std::cout <<  C_CYAN "showing default mutant stack\n" C_RESET LINE "\n" << std::endl;
	MutantStack<int> mstack;
	testMutantStack(mstack);


	promptEnter();

	// Testing with std::list as the underlying container
	std::cout << C_CYAN "showing list mutant stack\n" C_RESET LINE "\n" << std::endl;
	MutantStack<int, std::list<int>> listMstack;
	testMutantStack(listMstack);		
	


		
	return 0;
}
