/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:55:53 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/14 00:25:06 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
	public:
		Weapon(const std::string& type);
		~Weapon();

		void				setType(const std::string& type);
		const std::string&	getType(void) const;
	private:
		std::string		type_;
};
