/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:18:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/14 02:50:43 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <ostream>

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->val_ = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->val_;
}

void	Fixed::setRawBits(const int raw) {
	this->val_ = raw;
}
