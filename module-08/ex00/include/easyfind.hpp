/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:55:13 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/02/13 19:27:17 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>


//pass container BY REF (or ptr) else ITERATOR WILL BECOME INVALID
template <typename T>
typename T::iterator	easyfind(T &cont, int value)
{
	return (std::find(cont.begin(), cont.end(), value));
}

//if container doesn't have begin or end compile error will be given
//could use SFINAE or concepts to circumvent but they're c11 and c20 respectively
// think unnecesary for purpose of this exercise

//same if container doesn't hold ints

//associative containers are things like maps