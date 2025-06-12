/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:59:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/11 14:22:02 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

enum FIELDS {
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	SECRET,
	NB_FIELDS
};

class Contact {
	public:
		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickname(void) const;
		const std::string&	getPhoneNumber(void) const;
		const std::string&	getSecret(void) const;
		void				setFirstName(const std::string firstName);
		void				setLastName(const std::string lastName);
		void				setNickname(const std::string nickname);
		void				setPhoneNumber(const std::string phoneNumber);
		void				setSecret(const std::string secret);
	private:
		std::string	firstName_;
		std::string	lastName_;
		std::string	nickname_;
		std::string	phoneNumber_;
		std::string	secret_;
};
