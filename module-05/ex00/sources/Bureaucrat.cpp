/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:07 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/10/31 16:24:39 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{
	if (grade < MIN_GRADE)
		throw (Bureaucrat::GradeTooHighException()); //insert name?
	else if (grade > MAX_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	_grade = grade;

	std::cout << GREEN << "Bureaucrat: Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs.getName()), _grade(rhs.getGrade())
{
	std::cout << GREEN << "Bureaucrat: Copy constructor called" << RESET << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED << "Bureaucrat: Destructor called" << RESET << std::endl;
}



std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
	
	return (out << obj.getName() << ", bureaucrat grade " << obj.getGrade());
}

// ************************************************************************** //
//                               Get and setters                            //
// ************************************************************************** //

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

const unsigned int		&Bureaucrat::getGrade() const
{
	return (_grade);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void				Bureaucrat::Increment()
{
	_grade--;
	if (_grade < MIN_GRADE)
		throw (Bureaucrat::GradeTooHighException());
}
void				Bureaucrat::Decrement()
{
	_grade++;
	if (_grade > MAX_GRADE)
		throw (Bureaucrat::GradeTooLowException());
}


// ************************************************************************** //
//                                exceptions                              //
// ************************************************************************** //


const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade Too low!");
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade Too high!");
}


