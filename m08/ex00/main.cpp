/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:50:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 02:03:42 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main() {
	try {
		std::vector<int> container(3);
		container[0] = 4;
		container[1] = 42;
		container[2] = 420;

		int to_find = 42;
		std::vector<int>::iterator it = easyfind(container, to_find);
		if (it == container.end())
			std::cout << to_find << " not found in container" << std::endl;
		else {
			size_t index = it - container.begin();
			std::cout << to_find << " found at index " << index << std::endl;
		}

		*it = 24;

		it = easyfind(container, to_find);
		if (it == container.end())
			std::cout << to_find << " not found in container" << std::endl;
		else {
			size_t index = it - container.begin();
			std::cout << to_find << " found at index " << index << std::endl;
		}

		std::vector<int> empty_container;
		it = easyfind(empty_container, to_find);
	} catch (std::exception const& e) {
		std::cout << "Caught exception: " <<e.what() << std::endl;
	}
}
