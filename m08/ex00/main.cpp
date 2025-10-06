/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:50:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/01 01:15:02 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main() {
	std::vector<int> container(3);
	container[0] = 4;
	container[1] = 42;
	container[2] = 420;

	std::vector<int>::iterator it = easyfind(container, 42);
	it++;
	std::cout << *it << std::endl; // should print 420

	std::vector<int>::iterator it2 = easyfind(container, 420);
	it2++;
	if (it2 == container.end())
		std::cout << "end of vector reached" << std::endl;
	// std::cout << *container.end() << std::endl;
	// std::cout << *it << std::endl;
}
