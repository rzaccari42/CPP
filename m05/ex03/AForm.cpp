/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:34:26 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 18:20:35 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include <ostream>

AForm::AForm(std::string const& name, 
	unsigned int const& signGrade, 
	unsigned int const& execGrade) :
	name_(name), 
	signGrade_(signGrade),
	execGrade_(execGrade),
	isSigned_(false) {
	if (signGrade < 1)
		throw AForm::GradeTooHighException(SIGN_GRADE);
	if (execGrade < 1)
		throw AForm::GradeTooHighException(EXEC_GRADE);
	if (signGrade > 150)
		throw AForm::GradeTooLowException(SIGN_GRADE);
	if (execGrade > 150)
		throw AForm::GradeTooLowException(EXEC_GRADE);
}

AForm::AForm(AForm const& other) : 
	name_(other.name_),
	signGrade_(other.signGrade_),
	execGrade_(other.execGrade_),
	isSigned_(other.signGrade_) {}

AForm::~AForm() {}

AForm&	AForm::operator=(AForm const& rhs) {
	if (&rhs == this)
		return *this;
	this->isSigned_ = rhs.isSigned_;
	return *this;
}

std::string const&	AForm::getName() const {
	return this->name_;
}

unsigned int const&	AForm::getSignGrade() const {
	return this->signGrade_;
}

unsigned int const&	AForm::getExecGrade() const {
	return this->execGrade_;
}

bool const&	AForm::isSigned() const {
	return this->isSigned_;
}

void	AForm::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException(SIGN_BUREAUCRAT);
	this->isSigned_ = true;
}

void	AForm::execute(Bureaucrat const& executor) const {
	if (this->isSigned() == false)
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException(EXEC_BUREAUCRAT);
	executeAction();
}

std::ostream&	operator<<(std::ostream& os, AForm const& rhs) {
	os << "FORM INFORMATIONS" << std::endl;
	os << "name: " << rhs.getName() << std::endl;
	os << "signing grade: " << rhs.getSignGrade() << std::endl;
	os << "executing grade: " << rhs.getExecGrade() << std::endl;
	os << "signed: " << rhs.isSigned();
	return os;
}
