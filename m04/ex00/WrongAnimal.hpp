/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:57:47 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/02 19:22:38 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& rhs);

		void				setType(std::string& type);
		const std::string&	getType() const;

		void makeSound() const;
	protected:
		std::string type_;
};
