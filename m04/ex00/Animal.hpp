/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:34:17 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/01 21:27:12 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal {
	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

        Animal& operator=(const Animal& rhs);

		void				setType(std::string& type);
		const std::string&	getType(void) const;

		virtual void	makeSound(void) const;
	protected:
		std::string type_;
};
