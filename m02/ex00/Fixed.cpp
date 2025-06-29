/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:18:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 09:01:43 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : rawBits_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : rawBits_(other.rawBits_) {
	std::cout << "Copy constructor called" << std::endl;
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

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits_;
}

void	Fixed::setRawBits(const int raw) {
	this->rawBits_ = raw;
}
