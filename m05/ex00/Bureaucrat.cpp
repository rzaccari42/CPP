/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:12:19 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 15:35:08 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <ostream>

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

std::ostream&	operator<<(std::ostream& os, Bureaucrat const& rhs) {
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return os;
}
