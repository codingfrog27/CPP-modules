/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/03/31 18:44:34 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <random>
#include <ctime>
#include <iostream>
#include <sstream>
#include <regex>
#include <exception>

#define C_YELLOW "\033[33m"
#define C_RESET "\033[0m"
#define C_CYAN "\033[36m"
#define C_RED "\033[31m"
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


void	InputIsValid(std::string input)
{
	if (input.find_first_not_of("0132456789+-*/ ") != std::string::npos)
		throw (std::invalid_argument("Invalid character found in input"));
}

void	calculate(int op, std::stack<float> &stack)
{
	float a, b, result;
	if (stack.size() < 2)
		throw (std::invalid_argument("Wrong operator placement, need at least 2 preceding numbers"));
	
	a = stack.top();
	stack.pop();
	b = stack.top();
	stack.pop();

	switch (op)
	{
	case '+':
		result = b + a;
		break;
	case '-':
		result = b - a;
		break;
	case '/':
		result = b / a;
		break;
	case '*':
		result = b * a;
		break;
	default: 
		std::cerr << "WHATTTTEHIUAFHIUHFIUHEF\n\n" << std::endl; //should never reach but test
		break;
	}
	stack.push(result);
}

void	Tokenise(std::string	&input)
{
	std::regex	nbrs("^\\d+$");
	std::regex	ops("^(\\+|-|\\*|/)$");
	std::stack<float>	mathStack;
	std::istringstream	iss(input);
	std::string			current;
	// float				nbr;
	while (iss >> current)
	{
		if (std::regex_match(current, nbrs))
			mathStack.push(stof(current)); //shouldnt throw but test
		else if (std::regex_match(current, ops))
			calculate(current[0], mathStack);
		else 
			throw (std::invalid_argument("Invalid token detected"));
	}
	if (mathStack.size() > 1)
		throw (std::invalid_argument("too many numbers remaining"));
	std::cout << mathStack.top() << std::endl;
}


int main(int argc, char **argv) {
		
	if (argc != 2) {
		std::cerr << C_RED \
		"Error: Please give one and only one argument to RPN" C_RESET << std::endl;
	}
	std::string input = argv[1];
	try
	{
		InputIsValid(input);
		Tokenise(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << C_RED "Error: " C_RESET << e.what() << '\n';
	}
	
	
	
	return 0;
}


//wtf absolutely speedran this exercise pog??

//mostly cleanup, nicer func split and use class if i want, test some moer AND FINISH BBY



//reverse poloish notation
// always less then 10 numbers as input
// output result
// errors on cerr
// handle + - / and *
// no brackets or decimal handling needed

//parsed into abstract syntax trees??

//OR use a stack and as you read keep popping in numbers untill you find operator (+, - etc.)
// then if found pop last 2 operands from stack (2nd popped becomes first in calc), 
// calculate result and put result back into the stack

//stack -> last in first out is integral to left to right evaluation.. stack it is


//for tokenizing
//1 istringstream