/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:51:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/22 01:44:42 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

size_t	promptContactIndex() {
	size_t	index;
	std::cin >> index;
	if (std::cin.fail()) {
		std::cout << "ERROR: invalid input" << std::endl;
		std::cout << "\tvalue should be a positive integer" << std::endl;
		return 0;
	}
	return index;
}

int	promptContactInfos(std::string* data) {
	std::string	fields[5] = {
		"First name:",
		"Last name:",
		"Nickname:",
		"Phone number:",
		"Darkest secret:"
	};
	std::string	input;
	size_t		i = 0;
	while (i < NB_FIELDS) {
		std::cout << fields[i];
		std::cin >> input;
		if (std::cin.eof()) {
			std::cout << "error: EOF" << std::endl;
			return 0;
		}
		data[i] = input;
		i++;
	}
	return 1;
}

void	promptCmd(std::string& input) {
	std::cin >> input;
	if (std::cin.eof()) {
		std::cout << "error: EOF" << std::endl;
		std::exit(1);
	}
}

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input;	

	while (1) {
		promptCmd(input);
		if (input == "ADD") {
			std::string	data[5];
			if (promptContactInfos(data))
				phoneBook.addContact(data);
		}
		else if (input == "SEARCH") {
			phoneBook.displayPhoneBook();
			phoneBook.displayContact(promptContactIndex());
		}
		else if (input == "EXIT") {
			break;
		}
		else {
			std::cout << "Invalid input" << std::endl;
			continue;
		}
	}
	return 0;
}
