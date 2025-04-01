/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaggoun <vlaggoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:16:10 by vlaggoun          #+#    #+#             */
/*   Updated: 2025/04/01 19:05:14 by vlaggoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int	Fixed::getvalue() const
{
	return (this->_fixed_value);
}

Fixed	Fixed::operator*(const Fixed &value) const
{
	return (this->_fixed_value * value.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &value) const
{
	return (this->_fixed_value + value.getRawBits());
}

Fixed	Fixed::operator-(const Fixed &value) const
{
	return (this->_fixed_value - value.getRawBits());
}

Fixed	Fixed::operator/(const Fixed &value) const
{
	return (this->_fixed_value / value.getRawBits());
}

bool	Fixed::operator> (const Fixed &value) const
{
	return (this->_fixed_value > value.getRawBits());
}

bool	Fixed::operator< (const Fixed &value) const
{
	return (this->_fixed_value < value.getRawBits());
}

bool	Fixed::operator>= (const Fixed &value)
{
	return !(this->_fixed_value < value.getRawBits());
}

bool	Fixed::operator<= (const Fixed &value)
{
	return !(this->_fixed_value > value.getRawBits());
}

bool	Fixed::operator== (const Fixed &value)
{
	return (this->_fixed_value == value.getRawBits());
}

bool	Fixed::operator!= (const Fixed &value)
{
	return !(this->_fixed_value == value.getRawBits());
}

Fixed	&Fixed::operator++()
{
	return (*this);
}

Fixed	&Fixed::operator--()
{
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a <  b)
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a <  b)
		return (a);
	else
		return (b);
}


const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::operator=(const Fixed &value)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_value = value.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_value = raw;
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
	std::cout << std::setprecision(8);
	out << value.toFloat();
	return (out);
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

Fixed::Fixed(const Fixed &value)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = value;
}
