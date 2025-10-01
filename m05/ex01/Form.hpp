/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 23:38:59 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/27 14:13:49 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
	public:
		Form(std::string const& name, 
			unsigned int const& signGrade, 
			unsigned int const& execGrade);
		Form(Form const& other);
		~Form();

		Form& operator=(Form const& rhs);

		class GradeTooHighException;
		class GradeTooLowException;

		std::string const&	getName() const;
		unsigned int const&	getSignGrade() const;
		unsigned int const&	getExecGrade() const;
		bool const&			isSigned() const;
		void				beSigned(Bureaucrat const& bureaucrat);
	private:
		std::string const	name_;
		unsigned int const	signGrade_;
		unsigned int const	execGrade_;
		bool				isSigned_;
};

enum eContext { SIGN_GRADE, EXEC_GRADE, BUREAUCRAT_GRADE };

class Form::GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(eContext ctx) : ctx_(ctx) {}
		const char* what() const throw() {
			if (ctx_ == SIGN_GRADE)
				return "Form sign grade is too high";
			else if (ctx_ == EXEC_GRADE)
				return "Form execution grade is too high";
			else
				return "Invalid exception type provided";
		}
	private:
		eContext	ctx_;
};

class Form::GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(eContext ctx) : ctx_(ctx) {}
		const char* what() const throw() {
			if (ctx_ == SIGN_GRADE)
				return "Form sign grade is too low";
			else if (ctx_ == EXEC_GRADE)
				return "Form execution grade is too low";
			else 
				return "Bureaucrat grade is too low to sign";
		}
	private:
		eContext	ctx_;
};

std::ostream& operator<<(std::ostream& os, Form const& rhs);
