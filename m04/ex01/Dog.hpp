/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:36:23 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/02 18:01:30 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

        Dog& operator=(const Dog& rhs);

		Brain*	getBrain() const;
		void	makeSound() const;
	private:
		Brain*	brain_;
};
