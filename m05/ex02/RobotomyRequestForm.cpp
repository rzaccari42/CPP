/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:09:32 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 16:34:06 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const& target) :
	AForm("RobotomyRequest", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) :
	AForm(other), target_(other.target_) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	AForm::operator=(rhs);
	return *this;
}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "*whirrrr* *click‑click* *whirrrr* *DRRRR‑DRRRR*" << std::endl;  
	std::srand(time(NULL));
	if (std::rand() % 2)
		std::cout << this->target_ << " has been robotomized" << std::endl;
	else
		std::cout << this->target_ << " robotomy failed" << std::endl;
}
