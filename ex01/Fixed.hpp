/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaggoun <vlaggoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:31:31 by vlaggoun          #+#    #+#             */
/*   Updated: 2025/03/31 18:23:49 by vlaggoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <iomanip>

class	Fixed
{
public:

	Fixed(); // *default constructor
	~Fixed();
	Fixed(int const integer);
	Fixed(float	const flo);
	Fixed(const Fixed &value); // *copy constructor
	float	toFloat(void) const; // *convertit la valeur en virgule fixe en nombre à virgule flottante
	int	toInt(void) const; // *convertit la valeur en virgule fixe en nombre entier

	private:

	int	_fixed_value;
	static const int	_nbr_bits = 8;
};

std::ostream	&operator<< (std::ostream &out, Fixed const &value); /* insère une représentation en vir-
gule flottante du nombre à virgule fixe dans le flux de sortie (objet output stream)
passé en paramètre */
	#endif
