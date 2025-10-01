/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:03:10 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/30 15:46:37 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <climits>
#include <cfloat>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

static bool	is_char(std::string const& literal) {
	if (literal.length() > 1) return false;
	if (isprint(literal[0]) && !std::isdigit(literal[0])) return true;
	return false;
}

static bool	is_int(std::string const& literal) {
	errno = 0;
	char* end = 0;
	strtol(literal.c_str(), &end, 10);
	if (errno == ERANGE) return false;
	if (end == literal.c_str()) return false;
	if (*end != 0) return false;
	if (literal.find('.') != std::string::npos) return false;
	return true;
}

static bool	is_float(std::string const& literal) {
	errno = 0;
	char* end = 0;
	strtof(literal.c_str(), &end);
	if (errno == ERANGE) return false;
	if (end == literal.c_str()) return false;
	if (*end != 'f' && *(end + 1) != 0) return false;
	return true;
}

static bool	is_double(std::string const& literal) {
	errno = 0;
	char* end = 0;
	strtod(literal.c_str(), &end);
	if (errno == ERANGE) return false;
	if (end == literal.c_str()) return false;
	if (*end != 0) return false;
	return true;
}

static bool is_special(std::string const& literal) {
	if (literal == "nan" || literal == "nanf" ||
		literal == "inf" || literal == "inff" ||
		literal == "+inf" || literal == "+inff" ||
		literal == "-inf" || literal == "-inff")
		return true;
	return false;
}

static Type	detectType(std::string const& literal) {
	Type type = UNKNOWN;
	if (is_double(literal)) type = DOUBLE;
	if (is_float(literal)) type = FLOAT;
	if (is_int(literal)) type = INT;
	if (is_char(literal)) type = CHAR;
	if (is_special(literal)) type = SPECIAL;
	return type;
}

void	ScalarConverter::convertChar(char c) {
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) <<std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	ScalarConverter::convertInt(long i) {
	std::cout << "char: ";
	if (i < 0 || i > 127) std::cout << "Out of bounds" << std::endl;
	else if (isprint(i) == false) std::cout << "Non displayable" << std::endl;
	else std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: ";
	if (i < INT_MIN || i > INT_MAX) std::cout << "Out of bounds" << std::endl;
	else std::cout << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	ScalarConverter::convertFloat(float f) {
	std::cout << "char: ";
	if (f < 0 || f > 127) std::cout << "Out of bounds" << std::endl;
	else if (isprint(static_cast<int>(f)) == false) std::cout << "Non displayable" << std::endl;
	else std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	std::cout << "int: ";
	if (f < INT_MIN || f > INT_MAX) std::cout << "Out of bounds" << std::endl;
	else std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void	ScalarConverter::convertDouble(double d) {
	std::cout << "char: ";
	if (d < 0 || d > 127) std::cout << "Out of bounds" << std::endl;
	else if (isprint(static_cast<float>(d)) == false) std::cout << "Non displayable" << std::endl;
	else std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	std::cout << "int: ";
	if (d < INT_MIN || d > INT_MAX) std::cout << "Out of bounds" << std::endl;
	else std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d < FLT_MIN || d > FLT_MAX) std::cout << "Out of bounds" << std::endl;
	else std::cout << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	ScalarConverter::convertSpecial(std::string s) {
	if (s == "nan" || s == "nanf") {
		std::cout << "char: impossible" <<  std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nan" << std::endl;
		std::cout << "double: nanf" << std::endl;
	}
	else if (s == "+inf" || s == "+inff" ||
			 s == "inf" || s == "inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (s == "-inf" || s == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::convert(std::string const& literal) {
	std::stringstream s(literal);
	Type type = detectType(literal);
	switch (type) {
		case CHAR:
			char c;
			s >> c;
			convertChar(c);
			break;
		case INT:
			long i;
			s >> i;
			convertInt(i);
			break;
		case FLOAT:
			float f;
			s >> f;
			convertFloat(f);
			break;
		case DOUBLE:
			double d;
			s >> d;
			convertDouble(d);
			break;
		case SPECIAL:
			convertSpecial(literal);
			break;
		default:
			std::cout << "Error: invalid argument:";
			std::cout << "input can't be converted to any scalar type";
			std::cout << std::endl;
			break;
	}
}
