/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:53:51 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 00:37:12 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& scavTrap);
		~ScavTrap();
        ScavTrap& operator=(const ScavTrap& scavTrap);

		void	attack(const std::string& target);
		void	guardGate(void);
};
