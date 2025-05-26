/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 21:01:08 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/15 02:23:51 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();

		void	attack(void) const;
	private:
		std::string	name_;
		Weapon&		weapon_;
};
