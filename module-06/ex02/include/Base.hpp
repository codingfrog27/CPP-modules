/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:25:35 by mde-cloe          #+#    #+#             */
/*   Updated: 2025/01/24 15:14:33 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


class Base
{
	public:
		virtual ~Base() = default;
};

Base * generate(void);
void identify(Base *p);
void identify(Base& p);
