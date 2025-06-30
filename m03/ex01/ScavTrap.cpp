/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:38:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 00:37:26 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

ScavTrap::ScavTrap() : ClapTrap() {
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
	std::cout << "ScavTrap created with name " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap cloned" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) 
       ClapTrap::operator=(other);
    return *this;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0)
		return;
	this->energyPoints_--;
	std::cout << ">>>>>>>>>>" << std::endl;
	std::cout << "ScavTrap " << this->name_;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->attackDamage_;
	std::cout << " damage points!" << std::endl;
	std::cout << ">>>>>>>>>>" << std::endl << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "))))))))))" << std::endl;
	std::cout << "ScavTrap " << this->name_;
	std::cout << " is now in gate keeper mode" << std::endl;
	std::cout << "))))))))))" << std::endl << std::endl;
}
