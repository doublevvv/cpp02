/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaggoun <vlaggoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:48:43 by vlaggoun          #+#    #+#             */
/*   Updated: 2025/03/31 18:12:13 by vlaggoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ! 16777216 valeur trop grande a encoder pour int en fixed value (24 bits restants)

Fixed::Fixed(void) : _fixed_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}

Fixed::Fixed(int const integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_value = integer <<_nbr_bits;
}

Fixed::Fixed(float const flo)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_value = flo * (1 << _nbr_bits);
}

int	Fixed::toInt(void) const
{
	return (_fixed_value >> _nbr_bits);
}

float	Fixed::toFloat(void) const
{
	return (_fixed_value / (1 << _nbr_bits));
}

std::ostream	&operator<< (std::ostream &out, Fixed const &value)
{
	std::cout << std::fixed;
	std::cout << std::setprecision(2);
	out << value.toFloat();
	return (out);
}

