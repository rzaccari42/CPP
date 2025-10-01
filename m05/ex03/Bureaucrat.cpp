/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:12:19 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/28 22:48:30 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(std::string const& name, unsigned int const& grade) :
	name_(name), grade_(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) :
	name_(other.name_), grade_(other.grade_) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const& rhs) {
	if (&rhs == this)
		return *this;
	this->grade_ = rhs.grade_;
	return *this;
}

std::string const&	Bureaucrat::getName() const {
	return this->name_;
}

unsigned int const&	Bureaucrat::getGrade() const {
	return this->grade_;
}

void	Bureaucrat::upgrade() {
	if (this->grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade_--;
}

void	Bureaucrat::downgrade() {
	if (this->grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade_++;
}

void	Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed ";
		std::cout << form.getName();
		std::cout << std::endl;
	} catch (std::exception const& e) {
		std::cout << this->getName();
		std::cout << " couldn't sign ";
		std::cout << form.getName();
		std::cerr << " because: ";
		std::cerr << e.what();
		std::cout << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm& form) const {
	try {
		form.execute(*this);
		std::cout << this->getName();
		std::cout << " executed ";
		std::cout << form.getName();
		std::cout << std::endl;
	} catch (std::exception const& e) {
		std::cerr << this->getName();
		std::cerr << " can't execute ";
		std::cerr << form.getName();
		std::cerr << " because: ";
		std::cerr << e.what();
		std::cout << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
