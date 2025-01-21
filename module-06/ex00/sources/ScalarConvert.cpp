/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:00:31 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/01/21 18:56:43 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
bool	convertPsuedo(const std::string& literal);
bool	convertChar(const std::string& literal);
bool	convertInt(const std::string& literal);
bool	convertFloat(const std::string& literal);
bool	convertDouble(const std::string& literal);
void	printConverts(int i, float f, double d);


constexpr std::size_t npos = std::string::npos;



void	ScalarConverter::convert(std::string literal)
{
	if (literal.empty()){
		std::cout << "input is empty" << std::endl;
		return ;
	}
	using ConvertFunc = bool(*)(const std::string&);
	ConvertFunc convertFuncs[] = {
		convertChar,
		convertInt,
		convertFloat,
		convertDouble
	};

	for (auto& func : convertFuncs) {
		if (func(literal) == true)
			return;
	}
	std::cout << "no suitable conversion found :(" << std::endl;
}


//subject doesnt show char example but since it wants 0 to be nonprintable
//& asks for chars to be given w '' I've turned off using non quoted text
// only means you need double and single quotes for char
bool convertChar(const std::string& literal)
{
	int	c;
	
	if (literal.size() == 3 && literal.front() == '\'' \
		&& literal.back() == '\'')
		c = literal.at(1);
	// else if (literal.size() == 1)
	// 	c = literal.at(0);
	else
		return false;
	printConverts(c, static_cast<float>(c), \
					static_cast<double>(c));
	return true;
}

bool convertInt(const std::string& literal)
{
	if (literal.find('.') != npos)
		return false;
	try {
		int i = std::stoi(literal);
		printConverts(i, static_cast<float>(i), static_cast<double>(i));
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

bool convertFloat(const std::string& literal)
{
	if (literal.back() != 'f' && literal.back() != 'F')
		return (false);
	try {
		float f = std::stof(literal);
		printConverts(static_cast<int>(f), f, static_cast<double>(f));
		return true;
	} catch (const std::exception&) {
		return false;
	}
}

bool convertDouble(const std::string& literal) {
	try {
		double d = std::stod(literal);
		printConverts(static_cast<int>(d), static_cast<float>(d), d);
		return true;
	} catch (const std::exception&) {
		return false;
	}
}


void	printConverts(int i, float f, double d)
{
	if (i < 1 || i > 127)
		std::cout << "char: not possible" << std::endl; //should be saved as int first
	else if (i < 32 || i > 126)
		std::cout << "char: Non Displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(i) << '\'' << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}


// //inf is infinie and nan == not a number
// bool	convertPsuedo(const std::string& literal)
// {
// 	char		sign;
// 	std::string	printMe = literal;
// 	if (literal.find("inf") == 1 && literal.size() <= 5){
// 		sign = literal.front();
// 		if (sign != '-' && sign != '+')
// 			return (false); //throw bad arg?
// 	}
// 	else if (literal != "nan"){
// 		return (false);
// 		if (literal.rfind("ff") != std::string::npos)
// 			printMe.pop_back();
// 	}
// 	std::cout << "char: impossible" << std::endl;
// 	std::cout << "int: impossible"  << std::endl;
// 	std::cout << "float: " << printMe << "f" << std::endl;
// 	std::cout << "double: " << printMe << std::endl;
// }