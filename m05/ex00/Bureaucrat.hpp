/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:12:08 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/27 14:57:13 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <string>

class Bureaucrat {
	public:
		Bureaucrat(std::string const& name, unsigned int const& grade);
		Bureaucrat(Bureaucrat const& other);
		~Bureaucrat();

		Bureaucrat& operator=(Bureaucrat const& rhs);

		class GradeTooHighException;
		class GradeTooLowException;

		std::string const&	getName() const;
		unsigned int const&	getGrade() const;
		void				upgrade();
		void				downgrade();
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
