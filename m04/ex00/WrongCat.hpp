/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:03:09 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 19:23:52 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class WrongCat : public Animal {
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

        WrongCat& operator=(const WrongCat& rhs);

		void	makeSound() const;
};
