/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:59:29 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/11 14:16:22 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <sstream>

static std::string	promptInput(std::string label);
static std::string	formatColumn(std::string text, int width);

PhoneBook::PhoneBook() : index_(0) {}

void	PhoneBook::addContact() {
	std::string	data[5];
	std::string	fields[5] = {
		"First name: ",
		"Last name: ",
		"Nickname: ",
		"Phone number: ",
		"Darkest secret: "
	};
	for (size_t i = 0; i < NB_FIELDS; ++i)
		data[i] = promptInput(fields[i]);
	size_t index = (this->index_ > 7) ? this->index_ % 8 : this->index_;
	this->contacts_[index].setFirstName(data[FIRST_NAME]);
	this->contacts_[index].setLastName(data[LAST_NAME]);
	this->contacts_[index].setNickname(data[NICKNAME]);
	this->contacts_[index].setPhoneNumber(data[PHONE_NUMBER]);
	this->contacts_[index].setSecret(data[SECRET]);
	this->index_++;
}

void	PhoneBook::displayContact() const {
	size_t		index;
	std::string	input;

	if (index_ == 0) {
		std::cout << "No contact(s) to display" << std::endl;
		return;
	}
	while (1) {
		input = promptInput("Contact index: ");
		if (input.length() > 1) {
			std::cout << "ERROR: value in range [1-8] expected" << std::endl;
			continue;
		}
		index = input[0] - 48;
		if (index < 1 || index > 8) {
			std::cout << "ERROR: value in range [1-8] expected" << std::endl;
			continue;;
		}
		if (index > this->index_) {
			std::cout << "No contact registered at this index" << std::endl;
			continue;;
		}
		break;
	}
	index -= 1;
	std::cout << this->contacts_[index].getFirstName() << std::endl;
	std::cout << this->contacts_[index].getLastName() << std::endl;
	std::cout << this->contacts_[index].getNickname() << std::endl;
	std::cout << this->contacts_[index].getPhoneNumber() << std::endl;
	std::cout << this->contacts_[index].getSecret() << std::endl;
}

void	PhoneBook::displayPhoneBook(void) const {
	if (index_ == 0) {
		std::cout << "Phonebook is empty" << std::endl;
		return;
	}
	std::cout << formatColumn("INDEX", 10);
	std::cout << formatColumn("FIRST NAME", 10);
	std::cout << formatColumn("LAST NAME", 10);
	std::cout << formatColumn("NICKNAME", 10);
	std::cout << std::endl;
	
	size_t index = (this->index_ > 7) ? 8 : this->index_;
	for (size_t i = 0; i < index; ++i) {
		std::stringstream index;
		index << i + 1;
		std::cout << formatColumn(index.str(), 10);
		std::cout << formatColumn(contacts_[i].getFirstName(), 10);
		std::cout << formatColumn(contacts_[i].getLastName(), 10);
		std::cout << formatColumn(contacts_[i].getNickname(), 10);
		std::cout << std::endl;
	}
}

static std::string	promptInput(std::string label) {
	std::string	input;
	std::cout << label;
	std::getline(std::cin, input);
	if (std::cin.eof()) {
		std::cout << std::endl << "ERROR: EOF" << std::endl;
		std::exit(1);
	}
	if (input.empty()) {
		std::cout << "ERROR: empty input" << std::endl;
		promptInput(label);
	}
	input.erase(0, input.find_first_not_of(" "));
	input.erase(input.length(), input.find_last_not_of(" "));
	return input;
}

static std::string	formatColumn(std::string text, int width) {
	std::stringstream column;
	if (text.length() > 10) {
		text.resize(9);
		text += '.';
	}
	column << std::setw(width) << std::left << text << "|";
	return column.str();
}

