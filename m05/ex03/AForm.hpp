/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:23:57 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 18:38:25 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm {
	public:
		AForm(std::string const& name, 
			unsigned int const& signGrade, 
			unsigned int const& execGrade);
		AForm(AForm const& other);
		virtual ~AForm() = 0;

		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSigned;

		AForm& operator=(AForm const& rhs);

		std::string const&	getName() const;
		unsigned int const&	getSignGrade() const;
		unsigned int const&	getExecGrade() const;
		bool const&			isSigned() const;
		void				beSigned(Bureaucrat const& bureaucrat);
		void				execute(Bureaucrat const& executor) const;
	protected:
		virtual void		executeAction() const = 0;
	private:
		std::string const	name_;
		unsigned int const	signGrade_;
		unsigned int const	execGrade_;
		bool				isSigned_;
};

enum eContext { SIGN_GRADE, EXEC_GRADE, SIGN_BUREAUCRAT, EXEC_BUREAUCRAT };

class AForm::GradeTooHighException : public std::exception {
	public:
		GradeTooHighException(eContext ctx) : ctx_(ctx) {}
		const char* what() const throw() {
			switch (ctx_) {
				case SIGN_GRADE:
					return "Form sign grade is too high";
				case EXEC_GRADE:
					return "Form execution grade is too high";
				default:
					return "Invalid exception type provided";
			}
		}
	private:
		eContext	ctx_;
};

class AForm::GradeTooLowException : public std::exception {
	public:
		GradeTooLowException(eContext ctx) : ctx_(ctx) {}
		const char* what() const throw() {
			switch (ctx_) {
				case SIGN_GRADE:
					return "Form sign grade is too high";
				case EXEC_GRADE:
					return "Form execution grade is too high";
				case SIGN_BUREAUCRAT:
					return "Bureaucrat grade is too low to sign";
				case EXEC_BUREAUCRAT:
					return "Bureaucrat grade is too low to execute";
				default:
					return "Invalid exception type provided";
			}
		}
	private:
		eContext	ctx_;
};

class AForm::FormNotSigned : public std::exception {
	public:
		const char* what() const throw() {
			return "Form has not been signed";
		}
};

std::ostream& operator<<(std::ostream& os, AForm const& rhs);
