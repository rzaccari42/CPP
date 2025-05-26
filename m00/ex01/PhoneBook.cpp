/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:59:29 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/20 12:42:11 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>

void	PhoneBook::addContact(std::string data[5]) {
	size_t	index = 0;
	while (index < NB_FIELDS) {
		if (data[index].empty()) {
			std::cout << "ERROR: one or more fields are empty" << std::endl;
			std::cout << "\tcontact not registered" << std::endl;
			return;
		}
	}
	if (this->index_ > 7)
		this->index_ = this->index_ % 8;
	this->contacts_[index_].setFirstName(data[FIRST_NAME]);
	this->contacts_[index_].setLastName(data[LAST_NAME]);
	this->contacts_[index_].setNickname(data[NICKNAME]);
	this->contacts_[index_].setPhoneNumber(data[PHONE_NUMBER]);
	this->contacts_[index_].setSecret(data[SECRET]);
	this->index_++;
}

void	PhoneBook::displayContact(size_t index) const {
	if (index < 1 || index > 8) {
		std::cout << "ERROR: provided index is out of bounds" << std::endl;
		std::cout << "\tindex should be a value between 1 and 8" << std::endl;
		return;
	}
	index -= 1;
	std::cout << this->contacts_[index].getFirstName() << std::endl;
	std::cout << this->contacts_[index].getLastName() << std::endl;
	std::cout << this->contacts_[index].getNickname() << std::endl;
	std::cout << this->contacts_[index].getPhoneNumber() << std::endl;
	std::cout << this->contacts_[index].getSecret() << std::endl;
}

void	PhoneBook::displayPhoneBook(void) const {
	
}
