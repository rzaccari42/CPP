/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:54:41 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 21:14:01 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	randomChump("zombieStack");
	Zombie	*zombieHeap = newZombie("zombieHeap");
	zombieHeap->announce();
	delete zombieHeap;
	return 0;
}
