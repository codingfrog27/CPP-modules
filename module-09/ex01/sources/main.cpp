/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/03/17 13:36:32 by mde-cloe      #+#    #+#                 */
/*   Updated: 2025/08/08 18:11:08 by mde-cloe      ########   odam.nl         */
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




void	InputIsValid(std::string input)
{
	if (input.find_first_not_of("0132456789+-*/ ") != std::string::npos)
		throw (std::invalid_argument("Invalid character found in input"));
}

void	calculate(int op, std::stack<int> &stack)
{
	int a, b, result;
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
		if (a == 0)
			throw (std::invalid_argument("Division by zero is undefined"));
		result = b / a;
		break;
	case '*':
		result = b * a;
		break;
	default: 
		throw (std::invalid_argument("Invalid operator that somehow got through regex"));
	}
	stack.push(result);
}

void	Tokenise(std::string	&input)
{
	// int				nbrCount = 0;
	std::regex			nbrPattern("^\\d+$"); //doesnt check negative numbers but imo dont have to w how notation works
	int					nbr;
	std::regex			opPattern("^(\\+|-|\\*|/)$");
	std::stack<int>		mathStack;
	std::istringstream	iss(input);
	std::string			current;

	while (iss >> current)
	{
		if (std::regex_match(current, nbrPattern))
		{
			//haha oops its args less than 10 nbr value instead of
			// if (++nbrCount > 10)
			// 	throw (std::invalid_argument("no more than 10 nunbers allowed!"));
			nbr = stoi(current);
			if (nbr >= 10)
				throw (std::invalid_argument("no numbers bigger then 10 allowed!"));
			mathStack.push(nbr); 
		}
		else if (std::regex_match(current, opPattern))
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
		"Error:" C_RESET "Please give one and only one argument to RPN" << std::endl;
	}
	std::string input = argv[1];
	try
	{
		InputIsValid(input);
		Tokenise(input);
	}
	catch (const std::out_of_range &e)
	{
		std::cerr << C_RED "Error: " C_RESET "Number too large to be contained as int" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << C_RED "Error: " C_RESET << e.what() << '\n';
	}
	
	
	
	return 0;
}





//reverse poloish notation
// always less then 10 numbers as input
// output result
// errors on cerr
// handle + - / and *
// no brackets or decimal handling needed


//OR use a stack and as you read keep popping in numbers untill you find operator (+, - etc.)
// then if found pop last 2 operands from stack (2nd popped becomes first in calc), 
// calculate result and put result back into the stack

//stack -> last in first out is integral to left to right evaluation.. stack it is


//for tokenizing
//1 istringstream