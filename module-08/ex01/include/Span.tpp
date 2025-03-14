/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:03:12 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/03/14 17:17:03 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Span.hpp"
#include <iterator>

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{		
	if (elementCount + std::distance(begin, end) > N)
		throw ContainerFull("Not enough space to add the range of elements");
		
	for (Iterator it = begin; it != end; it++)
	{
		arr.at(elementCount) = *it;
		elementCount++;
	}
}
