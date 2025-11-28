/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:41:40 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/19 22:03:34 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <stdexcept>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: expression missing" << std::endl;
		std::cerr << "Usage: ./RPN [\"expression\"]" << std::endl;
		return 1;
	}

	try {
		std::cout << evalRPN(argv[1]) << std::endl;
	} catch (std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
