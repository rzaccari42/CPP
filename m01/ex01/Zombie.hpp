/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:59 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 20:37:10 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Zombie {
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void) const;
	private:
		std::string	name_;
};

Zombie*	zombieHorde(int N, std::string name); 
