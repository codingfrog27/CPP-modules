/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:45:47 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/03/12 19:08:47 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"



Span::Span(unsigned int N) : N(N), arr(N), elementCount(0)
{
}

Span::~Span()
{
}


void	Span::addNumber(int nbr)
{
	// if (this->arr.capacity() == arr.size())
	if(elementCount == N)
		throw (ContainerFull("Can't add number anymore"));
	arr.at(elementCount) = nbr;
	elementCount++;
}



//we can use sort to sort the container already so instead of looping over it N times
// we only need 1 loop
int		Span::shortestSpan()
{
	if (elementCount < 2)
		throw std::logic_error("Not enough elements to find a span");

	std::vector<int> sortedArr(arr.begin(), arr.begin() + elementCount);
	std::sort(sortedArr.begin(), sortedArr.end());

	int shortest = INT_MAX;
	for (unsigned int i = 1; i < sortedArr.size(); i++) {
		int span = sortedArr[i] - sortedArr[i - 1];
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}
int		Span::longestSpan()
{
	if (elementCount < 2)
		throw std::logic_error("Not enough elements to find a span");

	std::vector<int> sortedArr(arr.begin(), arr.begin() + elementCount);
	std::sort(sortedArr.begin(), sortedArr.end());

	int longest = 0;
	for (unsigned int i = 1; i < sortedArr.size(); i++) {
		int span = sortedArr[i] - sortedArr[i - 1];
		if (span > longest) {
			longest = span;
		}
	}
	return longest;
}