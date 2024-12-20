/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:29 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/30 20:35:41 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Colors.hpp"

#define MIN_GRADE 1
#define MAX_GRADE 150

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

	//getters
	const std::string		&getName() const;
	const unsigned int		&getGrade() const;
	// Public Methods
	void					Increment();
	void					Decrement();

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
};
	std::ostream			&operator<<(std::ostream &out, const Bureaucrat &obj);