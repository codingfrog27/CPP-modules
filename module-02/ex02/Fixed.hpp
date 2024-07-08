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
#include <cmath>

class Fixed {
public:
	// Constructors
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();

	//operator overloads
	Fixed& operator=(const Fixed &other);

	bool operator>(const Fixed &other); //left is implicitely passed since its a member function
	bool operator>=(const Fixed &other);
	bool operator<(const Fixed &other);
	bool operator<=(const Fixed &other);
	bool operator==(const Fixed &other);
	bool operator!=(const Fixed &other);

	Fixed operator+(const Fixed &other);
	Fixed  operator-(const Fixed &other);
	Fixed  operator*(const Fixed &other);
	Fixed  operator/(const Fixed &other);

	Fixed&  operator++();
	Fixed  operator++(int);
	Fixed&  operator--();
	Fixed operator--(int);

	//get and setters
	int	getRawBits (void) const;
	void setRawBits(int const raw);

	// Other member functions
	float	toFloat(void) const;
	int		toInt(void) const;
	static Fixed&	min(Fixed &first, Fixed &second);
	static const Fixed&	min(const Fixed &first, const Fixed &second);
	static Fixed&	max(Fixed &first, Fixed &second);
	static const Fixed&	max(const Fixed &first, const Fixed &second);

private:
	int					fixedNumberValue;
	static const int	fractional_bits_amount = 8;
	static const int	Float_convert_scale = 1 << 8; //= 256
};


	std::ostream &operator<<(std::ostream &stream, const Fixed &other);
#endif // !FIXED_HPP
