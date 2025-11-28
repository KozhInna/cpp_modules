/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:04:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/28 10:36:29 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawValue_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) : rawValue_(val << frBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : rawValue_(roundf(val * (1 << frBits))) {
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(rawValue_) / (1 << frBits);
}

int Fixed::toInt(void) const{
	return rawValue_ >> frBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : rawValue_(other.rawValue_) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		rawValue_ = other.rawValue_;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return rawValue_;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	rawValue_ = raw;
}