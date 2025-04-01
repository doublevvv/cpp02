/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaggoun <vlaggoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:16:08 by vlaggoun          #+#    #+#             */
/*   Updated: 2025/04/01 16:01:08 by vlaggoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <stdbool.h>

class	Fixed
{
public:

	Fixed(); // *default constructor
	Fixed(int const integer);
	Fixed(float	const flo);
	~Fixed();
	// * comparaisons
	Fixed	&operator= (const Fixed &value); // *copy assigment operator
	bool	operator> (const Fixed &value) const;
	bool	operator< (const Fixed &value) const;
	bool	operator>= (const Fixed &value);
	bool	operator<= (const Fixed &value);
	bool	operator== (const Fixed &value);
	bool	operator!= (const Fixed &value);
	// * arithmetique
	Fixed	operator+ (const Fixed &value) const;
	Fixed	operator- (const Fixed &value) const;
	Fixed	operator* (const Fixed &value) const;
	Fixed	operator/ (const Fixed &value) const;
	// * incrementation
	Fixed	&operator++(); // *prefix
	Fixed	&operator--(); // *prefix
	Fixed	operator++(int); // *postfix
	Fixed	operator--(int); // *postfix
	Fixed(const Fixed &value); // *copy constructor
	int	getvalue(void) const;

	// * public members functions
	Fixed	&min(Fixed &a, Fixed &b);
	Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	int	getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const; // *convertit la valeur en virgule fixe en nombre à virgule flottante
	int	toInt(void) const; // *convertit la valeur en virgule fixe en nombre entier

	private:

	int	_fixed_value;
	static const int	_nbr_bits = 8;
};

std::ostream	&operator<< (std::ostream &out, Fixed const &value);


#endif
