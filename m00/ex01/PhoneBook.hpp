/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:29:26 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/07 02:50:11 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <cstddef>
 
class PhoneBook {
	public:
		PhoneBook();  
		void	addContact(void);
		void	displayContact(void) const;
		void	displayPhoneBook(void) const;
	private:
		Contact	contacts_[8];
		size_t	index_;
};
