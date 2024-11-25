/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:43:56 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/25 15:14:12 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "AForm.hpp"


#define ASCII_TREE \
"       *\n" \
"      ***\n" \
"     *****\n" \
"    *******\n" \
"   *********\n" \
"  ******:)****\n" \
" *************\n" \
"***************\n" \
"      |||\n" \
"      |||\n"


// yurr
class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors and Destructors
		ShrubberyCreationForm(void) = delete;
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm(void);

		// Public Methods
		void				executeAction() const override;
};
