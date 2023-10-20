/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:11:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/19 18:42:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "main.h"

class Fixed{
  private:
    int fixedPointValue;
    static const int fractionalBits = 8;
  public:
    Fixed();
    Fixed(const Fixed &fixed);
    ~Fixed();
    Fixed & operator=(const Fixed &fixed);
    Fixed(const int nbr);
    Fixed(const float nbr);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
};

  std::ostream & operator<<(std::ostream& os, const Fixed& fixed);

#endif
