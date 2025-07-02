/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 03:15:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 19:20:18 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() :  Animal() {
	std::cout << "Default Cat constructor" << std::endl;
	this->type_ = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Copy Cat constructor" << std::endl;
	this->type_ = other.type_;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << this->type_;
	std::cout << " : Miaouuuuu!" << std::endl;
}
