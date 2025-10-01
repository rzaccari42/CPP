/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:58:58 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 18:26:17 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) :
	AForm("ShrubberyCreation", 145, 137), target_(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) :
	AForm(other), target_(other.target_) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& rhs) {
	AForm::operator=(rhs);
	return *this;
}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream file((this->target_ + "_shrubbery").c_str());
	if (!file.is_open()) {
		std::cerr << "error: file creation failed" << std::endl;
		return;
	}
	file << "	ccee88oo" << std::endl;
	file << " C8O8O8Q8PoOb o8oo" << std::endl;
	file << "dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      \\\\//  /douUP" << std::endl;
	file << "        \\\\////" << std::endl;
	file << "         |||/\\" << std::endl;
	file << "         |||\\/" << std::endl;
	file << "         |||||" << std::endl;
	file << "   .....//||||\\...." << std::endl;
}
