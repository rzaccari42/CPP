/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:33:01 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 02:12:44 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <string>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& ClapTrap);
		~ClapTrap();

        ClapTrap& operator=(const ClapTrap& fixed);

		const std::string&	getName(void) const;
		const int&			getHitPoints(void) const;
		const unsigned int&	getEnergyPoint(void) const;
		const unsigned int&	getAttackDamage(void) const;

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	protected:
		std::string		name_;
		int				hitPoints_;
		unsigned int	energyPoints_;
		unsigned int	attackDamage_;
};
