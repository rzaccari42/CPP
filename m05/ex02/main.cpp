/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 16:19:28 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 17:12:31 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main() {
	try {
		Bureaucrat bureaucrat("Smith", 10);
		std::cout << bureaucrat << std::endl;
		std::cout << "-------------------------" << std::endl;
		RobotomyRequestForm form("office");
		std::cout << form << std::endl;
		std::cout << "-------------------------" << std::endl;
		bureaucrat.signForm(form);
		std::cout << "-------------------------" << std::endl;
		std::cout << form << std::endl;
		std::cout << "-------------------------" << std::endl;
		RobotomyRequestForm formCopy(form);
		std::cout << formCopy << std::endl;
		std::cout << "-------------------------" << std::endl;
		bureaucrat.executeForm(form);
		// bureaucrat.upgrade();
		// bureaucrat.signForm(form);
		// std::cout << "-------------------------" << std::endl;
		// std::cout << form << std::endl;
	} catch (std::exception const& e) {
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
}
