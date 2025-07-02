/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 03:15:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 22:11:35 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat() : AAnimal() {
	this->type_ = "Cat";
	this->brain_ = new Brain();
	std::cout << "Default Cat constructor" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Copy Cat constructor" << std::endl;
	this->type_ = other.type_;
	this->brain_ = new Brain(*other.brain_);
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
	delete this->brain_;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	this->brain_ = rhs.brain_;
	return *this;
}

Brain*	Cat::getBrain() const {
	return this->brain_;
}

void	Cat::makeSound() const {
	std::cout << this->type_;
	std::cout << " : Miaouuuuu!" << std::endl;
}
