/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 02:05:03 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 21:10:45 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	this->type_ = "Dog";
	this->brain_ = new Brain();
	std::cout << "Default Dog constructor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy Dog constructor" << std::endl;
	this->type_ = other.type_;
	this->brain_ = new Brain(*other.brain_);
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete this->brain_;
}

Dog& Dog::operator=(const Dog& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	this->brain_ = rhs.brain_;
	return *this;
}

Brain* Dog::getBrain() const {
	return this->brain_;
}

void	Dog::makeSound() const {
	std::cout << this->type_;
	std::cout << " : Wouf Wouf!" << std::endl;
}
