/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:36:29 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 21:10:35 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat& other);
		~Cat();

        Cat& operator=(const Cat& rhs);

		Brain*	getBrain() const;
		void			makeSound() const;
	private:
		Brain*	brain_;
};
