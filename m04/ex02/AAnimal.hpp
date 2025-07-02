/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:34:17 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 22:04:50 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		virtual ~AAnimal();

        AAnimal& operator=(const AAnimal& rhs);

		void				setType(std::string& type);
		const std::string&	getType(void) const;

		virtual void	makeSound(void) const = 0;
	protected:
		std::string type_;
};
