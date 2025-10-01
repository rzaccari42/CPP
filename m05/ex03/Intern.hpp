/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:25:45 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/29 16:08:58 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <string>

class Intern {
	public:
		class InvalidFormName; 

		AForm*	makeForm(std::string const& formName, std::string const& formTarget);
};

class Intern::InvalidFormName : public std::exception {
	public:
		const char* what() const throw() {
			return "Invalid form name provided";
		}
};
