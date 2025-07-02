/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:17:24 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 21:12:45 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default Brain constructor called" << std::endl;
}


Brain::Brain(const Brain& other) {
	std::cout << "Copy Brain constructor called" << std::endl;
	for (size_t i = 0; i < 100; ++i) {
		this->ideas_[i] = other.ideas_[i];
	}
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs) {
	if (this == &rhs)
		return *this;
	for (size_t i = 0; i < 100; ++i) {
		this->ideas_[i] = rhs.ideas_[i];
	}
	return *this;
}

void	Brain::setIdea(size_t index, const std::string& idea) {
	if (index <= 100) {
		this->ideas_[index] = idea;
	}
}


const std::string&	Brain::getIdea(size_t index) const {
	if (index <= 100) {
		return this->ideas_[index];
	}
	return NULL;
}
