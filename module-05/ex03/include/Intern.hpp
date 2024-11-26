/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:48:49 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/26 13:22:34 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Intern
{
	private:
		// Private Attributes
		

	public:
		// Constructors and Destructors
		Intern(void);
		Intern(const Intern &rhs);
		Intern &operator=(const Intern &rhs);
		~Intern(void);
		AForm *makeForm(std::string formName, std::string target) const;
		class NonexistingForm : public std::exception
		{
			public:
				const char		*what() const noexcept override;	
		};
		// Public Methods

};
