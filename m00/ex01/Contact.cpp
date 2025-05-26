/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:24:12 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/12 00:26:26 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string&	Contact::getFirstName(void) const {
	return (this->firstName);
}

const std::string&	Contact::getLastName(void) const {
	return (this->lastName);
}

const std::string&	Contact::getNickname(void) const {
	return (this->nickname);
}

const std::string&	Contact::getSecret(void) const {
	return (this->secret);
}

void	Contact::setFirstName(const std::string firstName) {
	this->firstName = firstName;
}

void	Contact::setLastName(const std::string lastName) {
	this->lastName = lastName;
}

void	Contact::setNickname(const std::string nickname) {
	this->nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void	Contact::setSecret(const std::string secret) {
	this->secret = secret;
}
