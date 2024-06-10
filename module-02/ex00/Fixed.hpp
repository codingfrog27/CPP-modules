/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/10 19:52:16 by mde-cloe      #+#    #+#                 */
/*   Updated: 2024/06/10 19:52:16 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>

class Fixed {
public:
	// Constructors
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	int	getRawBits (void) const; //this const makes it a const member function and
	void setRawBits(int const raw); //
	// Setters
	// Other member functions

private:
	int					fixed_nbr_value;
	static const int	fractional_bits_amount = 8;
};


#endif // !FIXED_HPP


//learn
//  1 copy constructor syntax
//  2 operator overloads
// 3 const after a function declaration or after datatype

// deep copy is copy that also allocs new memory for data that the copied from
// object points to
