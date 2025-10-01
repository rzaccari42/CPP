/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:45:36 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 17:52:29 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main() {
	try {
		Bureaucrat bureaucrat("Smith", 11);
		std::cout << bureaucrat << std::endl;
		std::cout << "-------------------------" << std::endl;
		Form contract("internship", 10, 9);
		std::cout << contract << std::endl;
		std::cout << "-------------------------" << std::endl;
		// bureaucrat.upgrade();
		bureaucrat.signForm(contract);
		std::cout << "-------------------------" << std::endl;
		std::cout << contract << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "caught exception: " << e.what() << std::endl;
	}
}
