/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:15:57 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/15 01:45:50 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) 
	: name_(name), weapon_(weapon) {}

HumanA::~HumanA() {
	std::cout << name_ << " destroyed" << std::endl;
}

void	HumanA::attack(void) const {
	std::cout << name_; 
	std::cout << " attacks with their ";
	std::cout << weapon_.getType();
	std::cout << std::endl;
}
