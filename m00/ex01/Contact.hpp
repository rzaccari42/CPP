/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:59:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/20 12:12:48 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	secret;
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
};
