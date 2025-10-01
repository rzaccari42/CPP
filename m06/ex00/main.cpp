/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:16:59 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/29 16:56:28 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "error : program expect one argument" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
	ScalarConverter::convert(input);
}
