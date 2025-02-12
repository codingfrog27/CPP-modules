/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:55:13 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/02/12 17:10:22 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T cont, int value)
{
	typename T::iteraotor it = std::find(cont.begin(), cont.end(), value);
	//check for end and if so (aka not found) return end or else throw except

	//check for containers that dont have .begin or if they dont contrAIN INTS
	//CHECK CHATGPT LOG
}

