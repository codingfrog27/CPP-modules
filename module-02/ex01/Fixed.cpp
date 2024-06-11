/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 20:16:07 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/10 20:16:07 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	Fixed::Fixed()
	{
		std::cout << "Default constructor called.\n";
		fixedNumberValue = 0;
	}

	Fixed::Fixed(const Fixed &other)
	{
		std::cout << "copy constructor called.\n";
		*this = other;
	}

	Fixed::Fixed(const int value)
	{
		this->fixedNumberValue = value << fractional_bits_amount;
	}

	Fixed::Fixed(const float value)
	{
		this->fixedNumberValue = (int)roundf(value * Float_convert_scale);
	}

	Fixed& Fixed::operator=(const Fixed &other)
	{
		std::cout << "copy assignment operator called.\n";
		this->fixedNumberValue = other.fixedNumberValue;
		return (*this);
	}

	std::ostream& operator<<(std::ostream &stream, const Fixed &other)
	{
		stream << other.toFloat();
		return (stream);
	}

	Fixed::~Fixed()
	{
		std::cout << "Destructor called.\n";
	}

	int	Fixed::getRawBits (void) const
	{
		std::cout << "getRawBits member function called.\n";
		return (fixedNumberValue);
	}

	void Fixed::setRawBits(int const raw)
	{
		fixedNumberValue = raw;
	}

	float Fixed::toFloat(void) const
	{
		return ((float)this->fixedNumberValue / this->Float_convert_scale);
	}


	//since the last 8 bits in our fixed number represent the fractional bits
	// we just shift those away to get our actual int value
	int Fixed::toInt(void) const
	{
		return (fixedNumberValue >> fractional_bits_amount);
	}
