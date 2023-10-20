/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:11:18 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/19 18:38:36 by mamazzal         ###   ########.fr       */
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
    Fixed & operator=(const Fixed &fixed);
    ~Fixed();
    Fixed(const int nbr);
    Fixed(const float nbr);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    /*pre-decrement & pre-decrement	| ++test && --test  */
    Fixed & operator++(void);
    Fixed & operator--(void);
    /*post-increment & post-decrement	 test++ && test--*/
    Fixed operator++(int);
    Fixed operator--(int);
    /* 4 arithmetic operators */
    Fixed  operator+(const Fixed &fixed);
    Fixed  operator-(const Fixed &fixed);
    Fixed  operator*(const Fixed &fixed);
    Fixed  operator/(const Fixed &fixed);
    /* 6 comparison operators */
    bool operator>(const Fixed &fixed) const;
    bool operator<(const Fixed &fixed) const;
    bool operator<=(const Fixed &fixed) const;
    bool operator>=(const Fixed &fixed) const;
    bool operator==(const Fixed &fixed) const;
    bool operator!=(const Fixed &fixed) const;

    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};
  
  std::ostream & operator<<(std::ostream& os, const Fixed& fixed);

#endif
