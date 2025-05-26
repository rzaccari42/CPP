/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:42:22 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 20:36:17 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstddef>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	horde = new Zombie[N];
	for (size_t i = 0; i < (size_t)N; ++i) {
		new (horde + i) Zombie(name);
	}
	return horde;
}
