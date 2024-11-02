/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coding_frog <coding_frog@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:43:33 by coding_frog       #+#    #+#             */
/*   Updated: 2024/11/02 00:57:33 by coding_frog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class AForm
{
	private:
		const std::string	_name;
		const std::string	_target;
		const unsigned int	_minSignGrade;
		const unsigned int	_minExecGrade;
		bool				_isSigned;
	protected:	
		void				checkExecRights(Bureaucrat const &executor) const;
	public:
		// Constructors and Destructors
							AForm(void) = delete;
							AForm (std::string name, unsigned int grade);
							AForm(const std::string &name, const std::string &target, int signGrade, int execGrade);
							AForm(const AForm &rhs);
							AForm &operator=(const AForm &rhs) = delete;
							~AForm(void);
		//getters
		const std::string	&getName() const;
		const unsigned int	&getSignGrade() const;
		const unsigned int	&getExecGrade() const;
		const std::string	&getTarget() const;
		const bool			&getSignedStatus() const;
		// Public Methods
		void				beSigned(Bureaucrat &signer);
		virtual void		execute(Bureaucrat const & executor) const = 0;
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
		class NotSigned : public std::exception //passing a name would be possible but would need to make constructor and give it a name
		{
			public:
				const char		*what() const noexcept override;
		};
} ;

std::ostream				&operator<<(std::ostream &out, const AForm &obj);
