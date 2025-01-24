/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:26:20 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/24 18:09:00 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#define C_GREEN "\033[32m"
#define C_RESET "\033[0m"

template <typename T> class Array
{
	private:
		T 			*content;
		unsigned int count;
	public:
	//con (and de) structers
		Array() : content(new T[0]), count(0){};

		Array(unsigned int n): content(new T[n]), count(n)
		{
			for (size_t i = 0; i < count; i++)
				content[i] = T();
		}

		Array(const Array &rhs) : content(new T[rhs.count]), count(rhs.count){
			for (size_t i = 0; i < count; i++)
				content[i] = rhs.content[i];	
		}
		~Array() {delete[] content;}

	//operators
		Array & operator=(const Array &rhs) {
			if (this != &rhs)
			{
				delete[] content;
				count = rhs.count;
				content = new T[count];
				for (size_t i = 0; i < count; i++)
					content[i] = rhs.content[i];
			}
			return *this;
		}

		T& operator[](size_t index) const
		{
			if (index >= count)
				throw std::out_of_range("Index out of bounds");
			return content[index];
		}
	//and size lol
		size_t size() const { return (count);}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array) {
	for (size_t i = 0; i < array.size(); ++i)
		os << array[i] << " ";
	return os;
}