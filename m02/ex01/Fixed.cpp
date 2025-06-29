/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:18:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/29 11:00:15 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

Fixed::Fixed() : rawBits_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : rawBits_(other.rawBits_) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int& i) {
	std::cout << "Int constructor called" << std::endl;
	long long raw = static_cast<long long>(i) << fBits_;
	if (raw > INT_MAX || raw < INT_MIN) {
		std::cerr << "error: [int constructor] overflow in fixed-point conversion " << std::endl;
		this->rawBits_ = 0;
		return;
	}
	this->rawBits_ = static_cast<int>(raw);
}

Fixed::Fixed(const float& f) {
	std::cout << "Float constructor called" << std::endl;
	long long raw = static_cast<long long>(roundf(f * (1 << fBits_)));
	if (raw > INT_MAX || raw < INT_MIN) {
		std::cerr << "error: [float constructor] overflow in fixed-point conversion" << std::endl;
		this->rawBits_ = 0;
		return;
	}
	this->rawBits_ = static_cast<int>(raw);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->rawBits_ = rhs.rawBits_;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
	os << rhs.toFloat();
	return os;
}

void	Fixed::setRawBits(const int raw) {
	this->rawBits_ = raw;
}

int	Fixed::getRawBits(void) const {
	return this->rawBits_;
}

int		Fixed::toInt(void) const {
	return this->rawBits_ >> fBits_;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->rawBits_) / (1 << fBits_);
}
