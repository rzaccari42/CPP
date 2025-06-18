/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:51:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/18 17:01:57 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

void	promptCmd(std::string& input) {
	std::cout << "Enter command (ADD, SEARCH or EXIT)" << std::endl;
	std::cin >> input;
	if (std::cin.eof()) {
		std::cout << "error: EOF" << std::endl;
		std::exit(1);
	}
	std::cin.ignore();
}

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input;

	while (1) {
		promptCmd(input);
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH") {
			phoneBook.displayPhoneBook();
			phoneBook.displayContact();
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "Invalid input" << std::endl;
	}
	return 0;
}
