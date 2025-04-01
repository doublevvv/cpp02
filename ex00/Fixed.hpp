/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaggoun <vlaggoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:31:31 by vlaggoun          #+#    #+#             */
/*   Updated: 2025/03/31 16:55:46 by vlaggoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
public:

	Fixed(); // *default constructor
	Fixed(const Fixed &value); // *copy constructor
	Fixed	&operator= (const Fixed &value); // *copy assigment operator
	~Fixed(); //*destructor
	int	getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int	_fixed_value;
	static const int	_nbr_bits = 8;
};

#endif
