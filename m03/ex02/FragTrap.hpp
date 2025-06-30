/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 23:58:12 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 15:02:40 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		~FragTrap();

        FragTrap& operator=(const FragTrap& rhs);

		void	attack(const std::string& target);
		void	highFiveGuys(void);
};
