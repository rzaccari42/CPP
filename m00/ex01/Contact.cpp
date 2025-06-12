/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:24:12 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/11 14:22:45 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string&	Contact::getFirstName(void) const {
	return (this->firstName_);
}

const std::string&	Contact::getLastName(void) const {
	return (this->lastName_);
}

const std::string&	Contact::getNickname(void) const {
	return (this->nickname_);
}

const std::string&	Contact::getPhoneNumber(void) const {
	return (this->phoneNumber_);
}

const std::string&	Contact::getSecret(void) const {
	return (this->secret_);
}

void	Contact::setFirstName(const std::string firstName) {
	this->firstName_ = firstName;
}

void	Contact::setLastName(const std::string lastName) {
	this->lastName_ = lastName;
}

void	Contact::setNickname(const std::string nickname) {
	this->nickname_ = nickname;
}

void	Contact::setPhoneNumber(const std::string phoneNumber) {
	this->phoneNumber_ = phoneNumber;
}

void	Contact::setSecret(const std::string secret) {
	this->secret_ = secret;
}
