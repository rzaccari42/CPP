/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:02:10 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/29 16:40:46 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

typedef enum eType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	UNKNOWN
} Type;

class ScalarConverter {
	public:
		static void	convert(std::string const& literal);
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const& other);
		~ScalarConverter();

		ScalarConverter&	operator=(ScalarConverter const& rhs);

		static void	convertSpecial(std::string s);
		static void	convertChar(char c);
		static void	convertInt(long i);
		static void	convertFloat(float f);
		static void	convertDouble(double d);
};
