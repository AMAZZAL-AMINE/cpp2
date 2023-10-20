/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:08:54 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/19 18:02:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  this->fixedPointValue = 0;
}

Fixed::Fixed(Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  *this = fixed;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
  this->fixedPointValue = raw;
}

Fixed & Fixed::operator=(Fixed const &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixedPointValue = fixed.getRawBits();
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

