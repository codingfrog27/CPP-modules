/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-cloe <mde-cloe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:07 by mde-cloe          #+#    #+#             */
/*   Updated: 2024/11/25 15:34:49 by mde-cloe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp" //circ?

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
//                                exceptions                              //
// ************************************************************************** //


const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade is Too low!");
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade is Too high!");
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

void	Bureaucrat::signForm(Form &form) //???
	try
	{
		form.beSigned(*this);
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << _name << " couldn’t sign " << form.getName() << " because "\
		<< _name << "'s " << e.what() << std::endl;
		return;
	}
	catch(const std::exception &e)
	{
		std::cout << "I will never print :')" << std::endl;
		std::cerr << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
	
}
