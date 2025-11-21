/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:39:31 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/19 23:00:02 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main() {
	try {
		Array<int> arr(3);
		Array<int> arr2(arr);
		
		arr2[1] = 42;
		std::cout << arr[1] << std::endl;
		std::cout << arr2[1] << std::endl;
		// std::cout << arr[5] << std::endl;

		Array<std::string> sarr(3);
		sarr[1] = "Hello, world";
		std::cout << sarr[1] << std::endl;

		Array<std::string> const csarr(3);
		std::string s = csarr[1];
		std::cout << s << std::endl;

	} catch (std::exception const& e) {
		std::cerr << "exception caught: " << e.what() << std::endl;
		return 1;
	}
}
