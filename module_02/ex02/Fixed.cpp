/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:04:16 by ikozhina          #+#    #+#             */
/*   Updated: 2025/11/28 11:29:29 by ikozhina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawValue_(0) {}

Fixed::Fixed(const int val) : rawValue_(val << frBits) {}

Fixed::Fixed(const float val) : rawValue_(roundf(val * (1 << frBits))) {}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed res;
	res.rawValue_ = rawValue_ + other.rawValue_;
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed res;
	res.rawValue_ = rawValue_ - other.rawValue_;
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed res;
	res.rawValue_ = (static_cast<long long>(rawValue_) * other.rawValue_) >> frBits;
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed res;
	res.rawValue_ = (static_cast<long long>(rawValue_) << frBits) / other.rawValue_;
	return res;
}

//Pre-increment, post-increment, pre-decrement, post-decrement
Fixed& Fixed::operator++(){
	rawValue_ += 1;
	return *this;
}
Fixed& Fixed::operator--() {
	rawValue_ -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed old = *this;
	rawValue_ += 1;
	return old;
}

Fixed Fixed::operator--(int) {
	Fixed old = *this;
	rawValue_ -= 1;
	return old;
}

//comparison operators
bool Fixed::operator>(const Fixed& other) const {
	return rawValue_ > other.rawValue_;
}

bool Fixed::operator<(const Fixed& other) const {
	return rawValue_ < other.rawValue_;
}

bool Fixed::operator>=(const Fixed& other) const {
	return rawValue_ >= other.rawValue_;
}

bool Fixed::operator<=(const Fixed& other) const {
	return rawValue_ <= other.rawValue_;
}

bool Fixed::operator==(const Fixed& other) const {
	return rawValue_ == other.rawValue_;
}

bool Fixed::operator!=(const Fixed& other) const {
	return rawValue_ != other.rawValue_;
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
	return static_cast<float>(rawValue_) / (1 << frBits);
}

int Fixed::toInt(void) const {
	return rawValue_ >> frBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) : rawValue_(other.rawValue_) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		rawValue_ = other.rawValue_;
	return *this;
}

int Fixed::getRawBits(void) const {
	return rawValue_;
}

void Fixed::setRawBits(int const raw) {
	rawValue_ = raw;
}