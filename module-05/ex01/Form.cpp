#include "Form.hpp"



// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

Form::Form(std::string name, unsigned int grade) : _name(name)
{
	if (grade < MIN_GRADE)
		throw (Form::GradeTooHighException()); //insert name?
	else if (grade > MAX_GRADE)
		throw (Form::GradeTooLowException());
	_grade = grade;
	std::cout << GREEN << "Form: Default constructor called" << RESET << std::endl;
}

Form::Form(const Form &rhs) : _name(rhs.getName()), _grade(rhs.getGrade())
{
	std::cout << GREEN << "Form: Copy constructor called" << RESET << std::endl;
}

Form::~Form(void)
{
	std::cout << RED << "Form: Destructor called" << RESET << std::endl;
}



std::ostream &operator<<(std::ostream &out, const Form &obj)
{
	
	return (out << obj.getName() << ", Form grade " << obj.getGrade());
}

// ************************************************************************** //
//                               Get and setters                            //
// ************************************************************************** //

const std::string	&Form::getName() const
{
	return (_name);
}

const unsigned int		&Form::getGrade() const
{
	return (_grade);
}


// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

bool	Form::beSigned(Bureaucrat &signer)
{
	unsigned int grade = signer.getGrade();
	if (grade > this->_grade)
		throw (Form::GradeTooLowException());
	_isSigned = true;
}

// ************************************************************************** //
//                                exceptions                              //
// ************************************************************************** //


const char	*Form::GradeTooLowException::what() const noexcept
{
	return ("Grade Too low!" + _name);
}

const char	*Form::GradeTooHighException::what() const noexcept
{
	return ("Grade Too high!");
}
