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
		fixed_nbr_value = 0;
	}

	Fixed::Fixed(const Fixed &other)
	{
		std::cout << "copy constructor called.\n";
		this->fixed_nbr_value = other.fixed_nbr_value;
	}

	Fixed& Fixed::operator=(const Fixed &other)
	{
		std::cout << "copy assignment operator called.\n";
		this->fixed_nbr_value = other.fixed_nbr_value;
		return (*this);
	}

	Fixed::~Fixed()
	{
		std::cout << "Destructor called.\n";
	}

	int	Fixed::getRawBits (void) const
	{
		std::cout << "getRawBits member function called.\n";
		return (fixed_nbr_value);
	}

	void Fixed::setRawBits(int const raw)
	{
		fixed_nbr_value = raw;
	}
