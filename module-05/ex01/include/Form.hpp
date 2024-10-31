/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:43:33 by coding_frog       #+#    #+#             */
/*   Updated: 2024/10/31 16:21:52 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Form
{
	private:
		const std::string	_name;
		const unsigned int	_gradeRequired;
		bool				_isSigned;
		// Private Attributes
		

	public:
		// Constructors and Destructors
							Form(void) = delete;
							Form (std::string name, unsigned int grade);
							Form(const Form &rhs);
							Form &operator=(const Form &rhs) = delete;
							~Form(void);
		//getters
		const std::string	&getName() const;
		const unsigned int	&getGrade() const;
		// Public Methods
		void				beSigned(Bureaucrat &signer);
		//exceptions
		class GradeTooLowException : public std::exception
		{
			public:
				
				const char		*what() const noexcept override; // noexcept means no exceptions can occur during its execution
																//used to be throw() in older versions
		};  //wanted to define outside of class but subject states otherwise :(
		class GradeTooHighException : public std::exception //passing a name would be possible but would need to make constructor and give it a name
		{
			public:
				const char		*what() const noexcept override;
		};

} ;

std::ostream				&operator<<(std::ostream &out, const Form &obj);
