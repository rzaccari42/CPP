/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:45:36 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 17:51:46 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main() {
	try {
		Bureaucrat bureaucrat("Smith", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.upgrade();
		std::cout << bureaucrat << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "caught exception: " << e.what() << std::endl;
	}
}
