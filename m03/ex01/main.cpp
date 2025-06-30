/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:32:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 16:05:25 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <ostream>

// int	main(int argc, char **argv) {
// 	(void)argc;
// 	(void)argv;
// 	
// 	ClapTrap defClap;
// 	ScavTrap defScav;
//
// 	ScavTrap scav("Joe");
// 	std::cout << "HP : " << scav.getHitPoints() << std::endl;
// 	std::cout << "EP : " << scav.getEnergyPoint() << std::endl;
// 	std::cout << "AD : " << scav.getAttackDamage() << std::endl;
//
// 	ScavTrap scavClone(scav);
// 	scavClone.attack("ennemy");
// 	scavClone.guardGate();
// }

int	main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	// OBJECT CREATION
	// test default constructor
	ClapTrap clapDefault;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test parametrized constructor
	ScavTrap scav1("One");
	std::cout << "HP : " << scav1.getHitPoints() << std::endl;
	std::cout << "EP : " << scav1.getEnergyPoint() << std::endl;
	std::cout << "AD : " << scav1.getAttackDamage() << std::endl;
	std::cout << std::endl;
	ScavTrap scav2("Two");
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test copy constructor
	ScavTrap scavClone(scav1);
	std::cout << "HP : " << scav1.getHitPoints() << std::endl;
	std::cout << "EP : " << scav1.getEnergyPoint() << std::endl;
	std::cout << "AD : " << scav1.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test assignment operator
	std::cout << "ClapTrap " << clapDefault.getName() << std::endl;
	std::cout << "HP : " << clapDefault.getHitPoints() << std::endl;
	std::cout << "EP : " << clapDefault.getEnergyPoint() << std::endl;
	std::cout << "AD : " << clapDefault.getAttackDamage() << std::endl;
	clapDefault = scav1;
	std::cout << " is now " << clapDefault.getName() << std::endl;
	std::cout << "HP : " << clapDefault.getHitPoints() << std::endl;
	std::cout << "EP : " << clapDefault.getEnergyPoint() << std::endl;
	std::cout << "AD : " << clapDefault.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	
	// METHODS
	scav2.attack("ennemy");
	// test taking damage
	scav2.takeDamage(20);
	// test healing
	scav2.beRepaired(10);
	std::cout << "-------------------------------------------------"<< std::endl;
	// test no energy points case	
	while (clapDefault.getEnergyPoint() > 0)
		clapDefault.attack("ennemy");
	clapDefault.attack("ennemy");	// should do nothing
	clapDefault.beRepaired(1);	// should do nothing
	std::cout << "-------------------------------------------------"<< std::endl;
	// test no HP case
	scav2.takeDamage(115);
	scav2.beRepaired(1);	// should do nothing
}
