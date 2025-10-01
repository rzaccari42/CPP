/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:25:59 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 18:15:53 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

static AForm*	newShrubbery(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

static AForm*	newRobotomy(std::string const& target) {
	return new RobotomyRequestForm(target);
}

static AForm*	newPresidential(std::string const& target) {
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string const& formName, std::string const& formTarget) {
	std::string formTypes[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*newForm[])(std::string const&) = {
		newShrubbery,
		newRobotomy,
		newPresidential
	};
	for (size_t i = 0; i < 3; i++) {
		if (formName == formTypes[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return newForm[i](formTarget);
		}
	}
	throw InvalidFormName();
}
