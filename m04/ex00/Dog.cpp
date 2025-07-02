/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 02:05:03 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 19:19:37 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	std::cout << "Default Dog constructor" << std::endl;
	this->type_ = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy Dog constructor" << std::endl;
	this->type_ = other.type_;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << this->type_;
	std::cout << " : Wouf Wouf!" << std::endl;
}
