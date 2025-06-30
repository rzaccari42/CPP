/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:58:37 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 15:02:15 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
	std::cout << "Default FragTrap created" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
	std::cout << "FragTrap created with name " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap cloned" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	if (this != &rhs) 
       ClapTrap::operator=(rhs);
    return *this;
}

void	FragTrap::attack(const std::string& target) {
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0)
		return;
	this->energyPoints_--;
	std::cout << ">>>>>>>>>>" << std::endl;
	std::cout << "FragTrap " << this->name_;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->attackDamage_;
	std::cout << " damage points!" << std::endl;
	std::cout << ">>>>>>>>>>" << std::endl << std::endl;
}

void FragTrap::highFiveGuys(void) {
	std::cout << "~~~~~~~~~~" << std::endl;
	std::cout << "FragTrap " << this->name_;
	std::cout << " would like to high five with the bros" << std::endl;
	std::cout << "~~~~~~~~~~" << std::endl << std::endl;
}
