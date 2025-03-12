/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:35:26 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/03/12 19:05:56 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span
{
	private:
		const unsigned int	N;
		std::vector<int>	arr;
		int					elementCount;
	public:
				Span(unsigned int N);
				~Span();
		void	addNumber(int nbr);
		int		shortestSpan();
		int		longestSpan();
	class ContainerFull : public std::exception
	{
		private:
			std::string errorMsg;
		public:
			ContainerFull(const std::string& msg) : errorMsg(msg) {}
			virtual const char* what() const throw() {
				return errorMsg.c_str();
			}
	};
};