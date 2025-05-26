/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:39:39 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/14 00:31:42 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string& type) : type_(type) {}

Weapon::~Weapon() {
	std::cout << "Weapon destroyed" << std::endl;
}

void	Weapon::setType(const std::string& type) {
	this->type_ = type;
}

const std::string&	Weapon::getType(void) const {
	return this->type_;
}
