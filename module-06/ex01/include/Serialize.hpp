/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:45:12 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/23 20:53:48 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdint>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"


typedef struct Data
{
	std::string s1;
	int n;
	std::string s2;
} Data;

class Serialize
{
private:
	/* data */
public:
	Serialize(/* args */) = delete;
	Serialize(Serialize const &src) = delete;
	~Serialize() = delete;
	Serialize operator=(Serialize const &src) = delete;
	static uintptr_t serialize(Data *raw);
	static Data* deserialize(uintptr_t raw);
};
