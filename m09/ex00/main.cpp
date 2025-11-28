/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:55:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 13:51:42 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <stdexcept>

#define DATABASE_PATH "rates.csv"

int	main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Error: missing file" << std::endl;
		return 1;
	}
	try {
		BitcoinExchange bx;
		std::cout << "===LOADING DATABASE===" << std::endl;
		bx.loadDatabase(DATABASE_PATH);
		std::cout << "===RUNNING===" << std::endl;
		bx.run(argv[1]);
	} catch (std::runtime_error const& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;	
	}
}

// int	main(int argc, char** argv) {
// 	if (argc != 2) {
// 		std::cerr << "Error: missing file" << std::endl;
// 		return 1;
// 	}
// 	try {
// 		BitcoinExchange bx;
// 		std::cout << "===LOADING DATABASE===" << std::endl;
// 		bx.loadDatabase(DATABASE_PATH);
// 		std::cout << "===RUNNING===" << std::endl;
// 		bx.run(argv[1]);
// 	} catch (std::runtime_error& e) {
// 		std::cerr << "Error: " << e.what() << std::endl;
// 		return 1;	
// 	}
// }
