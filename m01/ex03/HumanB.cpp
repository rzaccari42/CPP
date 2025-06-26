/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:16:22 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/26 19:14:06 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <ostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL) {}

HumanB::~HumanB() {
	std::cout << this->name_ << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}

void	HumanB::attack(void) const {
	if (!(this->weapon_)) {
		std::cout << this->name_ << " has no weapon" << std::endl; 
		return;
	}
	std::cout << this->name_; 
	std::cout << " attacks with their ";
	std::cout << this->weapon_->getType();
	std::cout << std::endl;
}
