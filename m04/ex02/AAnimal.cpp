/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:57:50 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 22:08:29 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type_("[undefined]") {
	std::cout << "Default AAnimal constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "Copy AAnimal constructor" << std::endl;
	this->type_ = other.type_;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	return *this;
}

void	AAnimal::setType(std::string& type) {
	this->type_ = type;
}

const std::string&	AAnimal::getType(void) const {
	return this->type_;
}

void	AAnimal::makeSound() const {
	std::cout << "AAnimal " << this->type_;
	std::cout << " makes a sound" << std::endl;
}

