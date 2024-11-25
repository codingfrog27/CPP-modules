/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:13:54 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/25 15:14:41 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
	public:
		// Constructors and Destructors
		RobotomyRequestForm(void) = delete;
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &rhs);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm(void);

		// Public Methods
		void				executeAction() const override;
};
