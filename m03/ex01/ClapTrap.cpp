/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:39:30 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/24 11:46:53 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
	: name_("[unnamed]"), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
	std::cout << "Default ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) 
	: name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0) {
	std::cout << "ClapTrap created with name " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap cloned" << std::endl;
	this->name_ = other.name_;
	this->hitPoints_ = other.hitPoints_;
	this->energyPoints_ = other.energyPoints_;
	this->attackDamage_ = other.attackDamage_;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this == &other) 
		return *this;
	this->name_ = other.name_;
	this->hitPoints_ = other.hitPoints_;
	this->energyPoints_ = other.energyPoints_;
	this->attackDamage_ = other.attackDamage_;
	return *this;	
}

const std::string&	ClapTrap::getName(void) const {
	return this->name_;
}

const int&	ClapTrap::getHitPoints(void) const {
	return this->hitPoints_;
}

const unsigned int&	ClapTrap::getEnergyPoint(void) const {
	return this->energyPoints_;
}

const unsigned int&	ClapTrap::getAttackDamage(void) const {
	return this->attackDamage_;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0)
		return;
	this->energyPoints_--;
	std::cout << ">>>>>>>>>>" << std::endl;
	std::cout << "ClapTrap " << this->name_;
	std::cout << " attacks " << target;
	std::cout << ", causing " << this->attackDamage_;
	std::cout << " damage points!" << std::endl;
	std::cout << ">>>>>>>>>>" << std::endl << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints_ - (int)amount <= 0)
		this->hitPoints_ = 0;
	else
		this->hitPoints_ -= amount;
	std::cout << "!!!!!!!!!!" << std::endl;
	std::cout << "ClapTrap " << this->name_;
	std::cout << " takes " << amount;
	std::cout << " damage points and is now at " << this->hitPoints_;
	std::cout << " HP." << std::endl;
	std::cout << "!!!!!!!!!!" << std::endl << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints_ == 0 || this->hitPoints_ == 0)
		return;
	this->hitPoints_ += amount;
	this->energyPoints_--;
	std::cout << "++++++++++" << std::endl;
	std::cout << "ClapTrap " << this->name_;
	std::cout << " repaired itselft, recovering " << amount;
	std::cout << " HP and is now at " << this->hitPoints_;
	std::cout << " HP." << std::endl;
	std::cout << "++++++++++" << std::endl << std::endl;
}
