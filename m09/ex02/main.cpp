/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:16:43 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 17:27:14 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		PmergeMe sorter;
		sorter.run(argc, argv);
	}
	catch (const std::exception &e) {
		std::cerr << "Error:" << std::endl;
		return 1;
	}
	return 0;
}
