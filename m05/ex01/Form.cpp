/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:34:15 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/27 14:29:04 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form(std::string const& name, 
	unsigned int const& signGrade, 
	unsigned int const& execGrade) :
	name_(name), 
	signGrade_(signGrade),
	execGrade_(execGrade),
	isSigned_(false) {
	if (signGrade < 1)
		throw Form::GradeTooHighException(SIGN_GRADE);
	if (execGrade < 1)
		throw Form::GradeTooHighException(EXEC_GRADE);
	if (signGrade > 150)
		throw Form::GradeTooLowException(SIGN_GRADE);
	if (execGrade > 150)
		throw Form::GradeTooLowException(EXEC_GRADE);
}

Form::Form(Form const& other) : 
	Form(other.name_, other.signGrade_, other.execGrade_) {}

Form::~Form() {}

Form&	Form::operator=(Form const& rhs) {
	if (&rhs == this)
		return *this;
	this->isSigned_ = rhs.isSigned_;
	return *this;
}

std::string const&	Form::getName() const {
	return this->name_;
}

unsigned int const&	Form::getSignGrade() const {
	return this->signGrade_;
}

unsigned int const&	Form::getExecGrade() const {
	return this->execGrade_;
}

bool const&	Form::isSigned() const {
	return this->isSigned_;
}

void	Form::beSigned(Bureaucrat const& bureaucrat) {
	if (bureaucrat.getGrade() <= this->getSignGrade()) {
		std::cout << bureaucrat.getName() << " signed ";
		std::cout << this->getName() << std::endl;
		this->isSigned_ = true;
	}
	else {
		std::cout << bureaucrat.getName();
		std::cout << " couldn't sign ";
		std::cout << this->getName() << std::endl;
		throw Form::GradeTooLowException(BUREAUCRAT_GRADE);
	}
}

std::ostream&	operator<<(std::ostream& os, Form const& rhs) {
	os << "FORM INFORMATIONS" << std::endl;
	os << "name: " << rhs.getName() << std::endl;
	os << "signing grade: " << rhs.getSignGrade() << std::endl;
	os << "executing grade: " << rhs.getExecGrade() << std::endl;
	os << "signed: " << rhs.isSigned();
	return os;
}
