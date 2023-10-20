/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:12:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/10/19 18:37:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

Fixed::Fixed() {
  this->fixedPointValue = 0;
}

Fixed::Fixed(const Fixed &fixed) {
  *this = fixed;
}

Fixed::Fixed(const int nbr) {
  this->fixedPointValue = std::roundf(nbr * (1 << this->fractionalBits));
}

Fixed::Fixed(const float nbr) {
  this->fixedPointValue = static_cast<int>(std::roundf(nbr * (1 << fractionalBits)));
}

float Fixed::toFloat(void) const  {
  return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
  return this->fixedPointValue / (1 << this->fractionalBits);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
  return this->fixedPointValue;
}

Fixed & Fixed::operator=(const Fixed &fixed) {
  this->fixedPointValue = fixed.getRawBits();
  return *this;
}

std::ostream & operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

Fixed & Fixed::operator++(void) {
  ++this->fixedPointValue;
  return *this;
}

Fixed & Fixed::operator--(void) {
  --this->fixedPointValue;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;
  ++(*this);
  return tmp;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;
  --(*this);
  return tmp;
}

Fixed  Fixed::operator+(const Fixed &fixed) {
  Fixed tmp;
  tmp.fixedPointValue = this->fixedPointValue + fixed.fixedPointValue;
  return tmp;
}

Fixed  Fixed::operator-(const Fixed &fixed) {
  Fixed tmp;
  tmp.fixedPointValue = this->fixedPointValue - fixed.fixedPointValue;
  return tmp;
}

Fixed  Fixed::operator*(const Fixed &fixed) {
  Fixed tmp;
  tmp.fixedPointValue = this->fixedPointValue * fixed.fixedPointValue / (1 << fractionalBits);
  return tmp;
}

Fixed  Fixed::operator/(const Fixed &fixed) {
  Fixed tmp;
  tmp.fixedPointValue = this->fixedPointValue * (1 << fractionalBits) / fixed.fixedPointValue;
  return tmp;
}

bool Fixed::operator>(const Fixed &fixed) const {
  return this->fixedPointValue > fixed.fixedPointValue ? true : false;
}

bool Fixed::operator<(const Fixed &fixed) const {
  return this->fixedPointValue < fixed.fixedPointValue ? true : false;
}

bool Fixed::operator<=(const Fixed &fixed) const {
  return this->fixedPointValue >= fixed.fixedPointValue ? true : false;
}

bool Fixed::operator>=(const Fixed &fixed) const {
  return this->fixedPointValue >= fixed.fixedPointValue ? true : false;
}

bool Fixed::operator==(const Fixed &fixed) const {
  return this->fixedPointValue == fixed.fixedPointValue ? true : false;
}

bool Fixed::operator!=(const Fixed &fixed) const {
  return this->fixedPointValue != fixed.fixedPointValue ? true : false;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return a.fixedPointValue < b.fixedPointValue ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return a.fixedPointValue > b.fixedPointValue ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return a.fixedPointValue < b.fixedPointValue ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return a.fixedPointValue > b.fixedPointValue ? a : b;
}
