/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:29:26 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/22 09:04:55 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstddef>

class PhoneBook {
	public:
		PhoneBook();  
		void	addContact(std::string data[5]);
		void	displayContact(size_t index) const;
		void	displayPhoneBook(void) const;
	private:
		Contact	contacts_[8];
		size_t	index_;
};
