/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:11:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 17:40:41 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie() {
	std::cout << this->name_ << " destroyed" << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
