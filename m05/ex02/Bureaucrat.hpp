/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:12:08 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/29 16:18:08 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <exception>
#include <string>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat(std::string const& name, unsigned int const& grade);
		Bureaucrat(Bureaucrat const& other);
		~Bureaucrat();

		class GradeTooHighException;
		class GradeTooLowException;

		Bureaucrat& operator=(Bureaucrat const& rhs);

		std::string const&	getName() const;
		unsigned int const&	getGrade() const;
		void				upgrade();
		void				downgrade();
		void				signForm(AForm& form) const;
		void				executeForm(AForm& form) const;
	private:
		std::string	const	name_;
		unsigned int		grade_;
};

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Bureaucrat grade is too high";
		}
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Bureaucrat grade is too low";
		}
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& rhs);
