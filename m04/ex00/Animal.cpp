/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:57:50 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 19:19:49 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type_("[undefined]") {
	std::cout << "Default Animal constructor" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Copy Animal constructor" << std::endl;
	this->type_ = other.type_;
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	return *this;
}

void	Animal::setType(std::string& type) {
	this->type_ = type;
}

const std::string&	Animal::getType(void) const {
	return this->type_;
}

void	Animal::makeSound() const {
	std::cout << "Animal " << this->type_;
	std::cout << " makes a sound" << std::endl;
}

