/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:16:22 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/15 02:31:12 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name_(name), weapon_(NULL) {}

HumanB::~HumanB() {
	std::cout << name_ << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon_ = &weapon;
}

void	HumanB::attack(void) const {
	std::cout << name_; 
	std::cout << " attacks with their ";
	std::cout << weapon_->getType();
	std::cout << std::endl;
}
