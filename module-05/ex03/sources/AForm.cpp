#include "AForm.hpp"



// ************************************************************************** //
//                        Constructors and Destructors                        //
// ************************************************************************** //

AForm::AForm(const std::string &name, const std::string &target, int signGrade, int executeGrade)
: _name(name), _target(target), _minSignGrade(signGrade), _minExecGrade(executeGrade)
{
	if (_minSignGrade < MIN_GRADE || _minExecGrade < MIN_GRADE)
		throw (AForm::GradeTooHighException());
	else if (_minSignGrade > MAX_GRADE || _minExecGrade > MAX_GRADE)
		throw (AForm::GradeTooLowException());
	std::cout << GREEN << "AForm: Default constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &rhs)
: _name(rhs.getName()),  _target(rhs.getTarget()), \
_minSignGrade(rhs.getSignGrade()), _minExecGrade(rhs.getExecGrade())
{
	std::cout << GREEN << "AForm: Copy constructor called" << RESET << std::endl;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm: Destructor called" << RESET << std::endl;
}



std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
	
	return (out << obj.getName() << ", AForm sign grade " << obj.getSignGrade() << ", and execute grade " << obj.getExecGrade());
}

// ************************************************************************** //
//                               Get and setters                            //
// ************************************************************************** //

const std::string &AForm::getName() const {
	return (_name);
}

const unsigned int &AForm::getSignGrade() const {
	return (_minSignGrade);
}

const unsigned int	&AForm::getExecGrade() const {
	return (_minExecGrade);
}

const bool &AForm::getSignedStatus() const {
	return (_isSigned);
}
const std::string &AForm::getTarget() const{
	return (_target);
}

// ************************************************************************** //



// ************************************************************************** //
//                                Public methods                              //
// ************************************************************************** //

void	AForm::beSigned(Bureaucrat &signer)
{
	unsigned int grade = signer.getGrade();
	if (grade > this->_minSignGrade)
		throw (AForm::GradeTooLowException());
	_isSigned = true;
}
void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw::AForm::NotSigned();
	if (getExecGrade() < executor.getGrade())
		throw::AForm::GradeTooLowException();
	executeAction();
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
const char	*AForm::NotSigned::what() const noexcept
{
	return ("the form hasn't been signed yet!");
}