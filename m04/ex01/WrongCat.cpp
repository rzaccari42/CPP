/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:04:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 19:32:49 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : Animal() {
	std::cout << "Default WrongCat constructor" << std::endl;
	this->type_ = "Wrong Cat";
}

WrongCat::WrongCat(const WrongCat& other) : Animal(other) {
	std::cout << "Copy WrongCat constructor" << std::endl;
	this->type_ = other.type_;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
	if (this == &rhs)
		return *this;
	this->type_ = rhs.type_;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << this->type_;
	std::cout << " : sheeeeeeeeesh!" << std::endl;
}
