#include "AForm.hpp"



// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

AForm::AForm(std::string name, unsigned int grade) : _name(name), _gradeRequired(grade)
{
	if (grade < MIN_GRADE)
		throw (AForm::GradeTooHighException()); //insert name?
	else if (grade > MAX_GRADE)
		throw (AForm::GradeTooLowException());
	std::cout << GREEN << "AForm: Default constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &rhs) : _name(rhs.getName()), _gradeRequired(rhs.getGrade())
{
	std::cout << GREEN << "AForm: Copy constructor called" << RESET << std::endl;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm: Destructor called" << RESET << std::endl;
}



std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	
	return (out << obj.getName() << ", AForm grade " << obj.getGrade());
}

// ************************************************************************** //
//                               Get and setters                            //
// ************************************************************************** //

const std::string	&AForm::getName() const {
	return (_name);
}

const unsigned int	&AForm::getGrade() const {
	return (_gradeRequired);
}

const bool	&AForm::getSignedStatus() const {
	return (_isSigned);
}

// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void	AForm::beSigned(Bureaucrat &signer)
{
	unsigned int grade = signer.getGrade();
	if (grade > this->_gradeRequired)
		throw (AForm::GradeTooLowException());
	_isSigned = true;
}

// ************************************************************************** //
//                                exceptions                              //
// ************************************************************************** //


const char	*AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade Too low!");
}

const char	*AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade Too high!");
}
