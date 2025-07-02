/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:58:09 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/02 19:07:11 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type_("[undefined]") {
	std::cout << "Default WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Copy WrongAnimal constructor" << std::endl;
	this->type_ = other.type_;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	return *this;
}

void	WrongAnimal::setType(std::string& type) {
	this->type_ = type;
}

const std::string&	WrongAnimal::getType(void) const {
	return this->type_;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal " << this->type_;
	std::cout << " makes a sound" << std::endl;
}

