/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:32:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 16:05:37 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <ostream>

// int	main(int argc, char **argv) {
// 	(void)argc;
// 	(void)argv;
// 	
// 	ClapTrap defClap;
// 	FragTrap defFrag;
//
// 	FragTrap frag("Joe");
// 	std::cout << "HP : " << frag.getHitPoints() << std::endl;
// 	std::cout << "EP : " << frag.getEnergyPoint() << std::endl;
// 	std::cout << "AD : " << frag.getAttackDamage() << std::endl;
//
// 	FragTrap fragClone(frag);
// 	fragClone.attack("ennemy");
// 	fragClone.highFiveGuys();
// }
//
int	main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	// OBJECT CREATION
	// test default constructor
	ClapTrap clapDefault;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test parametrized constructor
	FragTrap frag1("One");
	std::cout << "HP : " << frag1.getHitPoints() << std::endl;
	std::cout << "EP : " << frag1.getEnergyPoint() << std::endl;
	std::cout << "AD : " << frag1.getAttackDamage() << std::endl;
	std::cout << std::endl;
	FragTrap frag2("Two");
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test copy constructor
	FragTrap fragClone(frag1);
	std::cout << "HP : " << frag1.getHitPoints() << std::endl;
	std::cout << "EP : " << frag1.getEnergyPoint() << std::endl;
	std::cout << "AD : " << frag1.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test assignment operator
	std::cout << "ClapTrap " << clapDefault.getName() << std::endl;
	std::cout << "HP : " << clapDefault.getHitPoints() << std::endl;
	std::cout << "EP : " << clapDefault.getEnergyPoint() << std::endl;
	std::cout << "AD : " << clapDefault.getAttackDamage() << std::endl;
	clapDefault = frag1;
	std::cout << " is now " << clapDefault.getName() << std::endl;
	std::cout << "HP : " << clapDefault.getHitPoints() << std::endl;
	std::cout << "EP : " << clapDefault.getEnergyPoint() << std::endl;
	std::cout << "AD : " << clapDefault.getAttackDamage() << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	
	// METHODS
	frag2.attack("ennemy");
	// test taking damage
	frag2.takeDamage(5);
	// test healing
	frag2.beRepaired(1);
	std::cout << "-------------------------------------------------"<< std::endl;
	// test no energy points case	
	while (clapDefault.getEnergyPoint() > 0)
		clapDefault.attack("ennemy");
	clapDefault.attack("ennemy");	// should do nothing
	clapDefault.beRepaired(1);	// should do nothing
	std::cout << "-------------------------------------------------"<< std::endl;
	// test no HP case
	frag2.takeDamage(115);
	frag2.beRepaired(1);	// should do nothing
}
