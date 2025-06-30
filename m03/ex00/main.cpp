/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:32:20 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/29 15:02:54 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

int	main(int argc, char **argv) {
	(void)argc;
	(void)argv;

	// OBJECT CREATION
	// test default constructor
	ClapTrap clapDefault;
	std::cout << "ClapTrap " << clapDefault.getName() << " created" << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test parametrized constructor
	ClapTrap clap1("One");
	std::cout << "ClapTrap " << clap1.getName() << " created" << std::endl;
	std::cout << std::endl;
	ClapTrap clap2("Two");
	std::cout << "ClapTrap " << clap2.getName() << " created" << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test copy constructor
	ClapTrap clapClone(clap1);
	std::cout << "ClapTrap " << clapClone.getName() << " created" << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	// test assignment operator
	std::cout << "ClapTrap " << clapDefault.getName();
	clapDefault = clap1;
	std::cout << " is now " << clapDefault.getName() << std::endl;
	std::cout << std::endl;
	std::cout << "-------------------------------------------------"<< std::endl;
	
	// METHODS
	clapDefault.attack("ennemy");
	// test taking damage
	clapDefault.takeDamage(5);
	// test healing
	clapDefault.beRepaired(1);
	std::cout << "-------------------------------------------------"<< std::endl;
	// test no energy points case	
	while (clap1.getEnergyPoint() > 0)
		clap1.attack("ennemy");
	clap1.attack("ennemy");	// should do nothing
	clap1.beRepaired(1);	// should do nothing
	std::cout << "-------------------------------------------------"<< std::endl;
	// test no HP case
	clap2.takeDamage(15);
	clap2.beRepaired(1);	// should do nothing
}
