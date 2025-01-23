/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:28:38 by coding_frog       #+#    #+#             */
/*   Updated: 2025/01/23 21:29:48 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"



uintptr_t Serialize::serialize(Data *raw)
{
	uintptr_t ret = reinterpret_cast<uintptr_t>(raw);
	return ret;
}

Data* Serialize::deserialize(uintptr_t raw)
{
	Data *ret = reinterpret_cast<Data *>(raw);
	return ret;
}
