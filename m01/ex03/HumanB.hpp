/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:01:25 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/15 02:27:59 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(const std::string& name);
		~HumanB();

		void	setWeapon(Weapon& weapon);
		void	attack(void) const;
	private:
		std::string	name_;
		Weapon*		weapon_;
};
