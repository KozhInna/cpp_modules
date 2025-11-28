/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:04:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/27 21:15:51 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): value_(0) {}

Fixed::Fixed(const int val): value_(val << frBits) {}

Fixed::Fixed(const float val): value_(roundf(val * (1 << frBits))) {}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->value_ + other.value_);
    return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed res;
    res.setRawBits(this->value_ - other.value_);
    return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
    float result = this->toFloat() * other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator/(const Fixed& other) const {
    float result = this->toFloat() / other.toFloat();
    return Fixed(result);
}

//Pre-increment, post-increment, pre-decrement, post-decrement
Fixed& Fixed::operator++(){
    value_ += 1;
    return *this;
}
Fixed& Fixed::operator--() {
    value_ -= 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old = *this;
    value_ += 1;
    return old;
}

Fixed Fixed::operator--(int) {
    Fixed old = *this;
    value_ -= 1;
    return old;
}

//comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return value_ > other.value_;
}

bool Fixed::operator<(const Fixed& other) const {
    return value_ < other.value_;
}

bool Fixed::operator>=(const Fixed& other) const {
    return value_ >= other.value_;
}

bool Fixed::operator<=(const Fixed& other) const {
    return value_ <= other.value_;
}

bool Fixed::operator==(const Fixed& other) const {
    return value_ == other.value_;
}

bool Fixed::operator!=(const Fixed& other) const {
    return value_ != other.value_;
}

//return min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
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

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) : value_(other.value_) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->value_ = other.value_;
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->value_;
}

void Fixed::setRawBits(int const raw) {
    value_ = raw;
}