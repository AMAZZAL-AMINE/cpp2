/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:12:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/19 18:41:39 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

Fixed::Fixed(const int nbr) {
  this->fixedPointValue = nbr * (1 << this->fractionalBits);
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) {
  this->fixedPointValue = static_cast<int>(std::roundf(nbr * (1 << fractionalBits)));
  std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
  return this->fixedPointValue /  (1 << this->fractionalBits);
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  return this->fixedPointValue;
}

std::ostream & operator<<(std::ostream& cout, const Fixed& fixed) {
  cout << fixed.toFloat();
  return cout;
}

Fixed & Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixedPointValue = fixed.getRawBits();
  return *this;
}
