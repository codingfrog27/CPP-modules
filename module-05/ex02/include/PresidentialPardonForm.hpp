/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:54 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/25 15:18:27 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	public:
		// Constructors and Destructors
		PresidentialPardonForm(void) = delete;
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &rhs);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm(void);

		// Public Methods
		void				executeAction() const override;
};
