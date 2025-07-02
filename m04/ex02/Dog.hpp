/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:36:23 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 22:09:55 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

        Dog& operator=(const Dog& rhs);

		Brain*	getBrain() const;
		void			makeSound() const;
	private:
		Brain*	brain_;
};
