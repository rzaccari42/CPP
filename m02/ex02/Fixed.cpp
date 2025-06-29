/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:18:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/29 13:28:04 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <climits>

Fixed::Fixed() : rawBits_(0) {}

Fixed::Fixed(const Fixed& other) : rawBits_(other.rawBits_) {}

Fixed::Fixed(const int& i) {
	long long raw = static_cast<long long>(i) << fBits_;
	if (raw > INT_MAX || raw < INT_MIN) {
		std::cerr << "error: [int constructor] overflow in fixed-point conversion " << std::endl;
		this->rawBits_ = 0;
		return;
	}
	this->rawBits_ = static_cast<int>(raw);
}

Fixed::Fixed(const float& f) {
	long long raw = static_cast<long long>(roundf(f * (1 << fBits_)));
	if (raw > INT_MAX || raw < INT_MIN) {
		std::cerr << "error: [float constructor] overflow in fixed-point conversion" << std::endl;
		this->rawBits_ = 0;
		return;
	}
	this->rawBits_ = static_cast<int>(raw);
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->rawBits_ = other.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& other) {
	return this->rawBits_ > other.rawBits_;
}

bool	Fixed::operator<(const Fixed& other) {
	return this->rawBits_ < other.rawBits_;
}

bool	Fixed::operator>=(const Fixed& other) {
	return this->rawBits_ >= other.rawBits_;
}

bool	Fixed::operator<=(const Fixed& other) {
	return this->rawBits_ <= other.rawBits_;
}

bool	Fixed::operator==(const Fixed& other) {
	return this->rawBits_ == other.rawBits_;
}

bool	Fixed::operator!=(const Fixed& other) {
	return this->rawBits_ != other.rawBits_;
}

Fixed Fixed::operator+(const Fixed& other) {
	long long lhs = static_cast<long long>(this->rawBits_);
	long long rhs = static_cast<long long>(other.rawBits_);
	long long res = (lhs + rhs);
	if (res > INT_MAX) {
		std::cerr << "error: integer overflow" << std::endl;
		return *this;
	}
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) {
	long long lhs = static_cast<long long>(this->rawBits_);
	long long rhs = static_cast<long long>(other.rawBits_);
	long long res = (lhs - rhs);
	if (res < INT_MIN) {
		std::cerr << "error: integer overflow" << std::endl;
		return *this;
	}
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) {
	long long lhs = static_cast<long long>(this->rawBits_);
	long long rhs = static_cast<long long>(other.rawBits_);
	long long res = (lhs * rhs) >> fBits_;
	if (res > INT_MAX || res < INT_MIN) {
		std::cerr << "error: fixed-point overflow in multiplication" << std::endl;
		return *this;
	}
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) {
	if (other.toFloat() == 0.0f) {
		std::cerr << "error: division by zero" << std::endl;
		return *this;
	}
	if (this->rawBits_ == INT_MIN && other.rawBits_ == -1) {
        std::cerr << "error: fixed-point overflow in division" << std::endl;
        return *this;
    }
	long long lhs = static_cast<long long>(this->rawBits_);
	long long rhs = static_cast<long long>(other.rawBits_);
	long long res = (lhs / rhs) << fBits_;
	if (res > INT_MAX || res < INT_MIN) {
		std::cerr << "error: fixed-point overflow in division" << std::endl;
		return *this;
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void) {
	if (this->rawBits_ == INT_MAX) {
		std::cerr << "error: increment overflow" << std::endl;
		return *this;
	}
	this->rawBits_ += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed ret(*this);
	if (this->rawBits_ == INT_MAX) {
		std::cerr << "error: increment overflow" << std::endl;
		return *this;
	}
	this->rawBits_ += 1;
	return ret;
}

Fixed& Fixed::operator--(void) {
	if (this->rawBits_ == INT_MIN) {
		std::cerr << "error: decrement overflow" << std::endl;
		return *this;
	}
	this->rawBits_ -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed ret(*this);
	if (this->rawBits_ == INT_MIN) {
		std::cerr << "error: decrement overflow" << std::endl;
		return *this;
	}
	this->rawBits_ -= 1;
	return ret;
}

std::ostream& operator<<(std::ostream& os, const Fixed& other) {
	os << other.toFloat();
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

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a.rawBits_ < b.rawBits_)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.rawBits_ < b.rawBits_)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a.rawBits_ > b.rawBits_)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.rawBits_ > b.rawBits_)
		return a;
	return b;
}
