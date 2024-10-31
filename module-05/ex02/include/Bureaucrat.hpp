/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:29 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/31 19:31:40 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Colors.hpp"

#define MIN_GRADE 1
#define MAX_GRADE 150

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		// Private Attributes
		

	public:
		
	// Constructors and Destructors
							Bureaucrat() = delete;
							Bureaucrat(const std::string name, unsigned int grade);
							Bureaucrat(const Bureaucrat &rhs);
							~Bureaucrat(void);
	Bureaucrat				&operator=(const Bureaucrat &rhs) = delete; //doesnt work w const name

	// Public Methods
	const std::string		&getName() const;
	const unsigned int		&getGrade() const;
	void					Increment();
	void					Decrement();	
	void					signForm(Form &form);


	// exceptions
	class GradeTooLowException : public std::exception
	{
		public:
			const char		*what() const noexcept override;
	};
	class GradeTooHighException : public std::exception
	{
		public:
			const char		*what() const noexcept override;
	};
	class FormNotSigned : public std::exception
	{
		public:
			const char		*what() const noexcept override;
	}
};
	std::ostream			&operator<<(std::ostream &out, const Bureaucrat &obj);