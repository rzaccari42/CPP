/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:31:16 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/28 20:19:34 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const& target) :
	AForm("PresidentialPardon", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) :
	AForm(other), target_(other.target_) {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const& rhs) {
	AForm::operator=(rhs);
	return *this;
}

void	PresidentialPardonForm::executeAction() const {
	std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
