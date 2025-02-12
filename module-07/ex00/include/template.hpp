/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:26:20 by coding_frog       #+#    #+#             */
/*   Updated: 2025/02/12 16:18:44 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T> void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T	min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T> T	max(T a, T b)
{
	return (a > b ? a : b);
}

//thought id use conditional/ternary operators
// it goes <expression> ?(if true) <value> :(else) <value>
// aka if the thing before the ? is true the value will be first value and if not
// it will be the value after :
// basically a shorter if else with only values