/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:54:41 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 21:13:03 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstddef>

int	main() {
	size_t	horde_size = 10;
	Zombie *horde = zombieHorde(horde_size, "zombieUnit");
	for (size_t i = 0; i < horde_size; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}
