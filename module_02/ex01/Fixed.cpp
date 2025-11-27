/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:04:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/26 21:54:56 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): value_(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val): value_(val << frBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val): value_(roundf(val * (1 << frBits))) {
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(value_) / (1 << frBits);
}

int Fixed::toInt(void) const{
    return value_ >> frBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl; 
    if (this != &other)
        this->value_ = other.value_;
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value_;
}

void Fixed::setRawBits(int const raw) {
    value_ = raw;
}