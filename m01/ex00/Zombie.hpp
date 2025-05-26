/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:01:59 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 17:16:34 by razaccar         ###   ########.fr       */
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

Zombie*	newZombie(std::string name); 
void	randomChump(std::string name); 
