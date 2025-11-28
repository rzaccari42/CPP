/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:59:04 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 16:08:08 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string const& database) {
	this->loadDatabase(database);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) {
	database_ = other.database_;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& rhs) {
	if (this != &rhs)
		database_ = rhs.database_;
	return *this;
}

std::map<std::string, double> const&	BitcoinExchange::getDatabase() const {
	return database_;
}

void	BitcoinExchange::loadDatabase(std::string const& path) {
	if (path.substr(path.length() - 4, std::string::npos) != ".csv")
		throw std::runtime_error("invalid extension: .csv file expected");

	std::map<std::string, double>	tmp;
	std::ifstream					file;
	std::string						line;

	openFile(path, file);
	std::getline(file, line);
	if (line.empty() && file.eof())
		throw std::runtime_error("database file is empty");
	while (isEmptyLine(line))
		std::getline(file, line);
	while (std::getline(file, line)) {
		if (isEmptyLine(line))
			continue;
		size_t sep = line.find(',');
		if (sep == std::string::npos)
			throw std::runtime_error("invalid format: " + line);
		std::string date = parseDate(line.substr(0, sep));
		double		rate = parseValue(line.substr(sep + 1, std::string::npos));
		tmp[date] = rate;
	}
	database_.swap(tmp);
	std::cout << "using data from: " << path << std::endl;
}

void	BitcoinExchange::run(std::string const& path) const {
	std::ifstream	input;
	std::string		line;

	if (database_.empty())
		throw std::runtime_error("no database has been loaded");
	openFile(path, input);
	std::getline(input, line);
	if (line.empty() && input.eof())
		throw std::runtime_error("input file is empty");
	while (isEmptyLine(line))
		std::getline(input, line);
	while (std::getline(input, line)) {
		if (isEmptyLine(line))
			continue;
		size_t sep = line.find('|');
		if (sep == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		try {
			std::string date = parseDate(line.substr(0, sep - 1));
			double		value = parseValue(line.substr(sep + 1, std::string::npos));
			if (value > 1000) {
				std::cerr << "Error: number too big" << std::endl;
				continue;
			}
			double rate = getRateOnDate(date);
			std::cout << date << " => " << value << " = ";
			std::cout << value * rate << std::endl;
		} catch (std::runtime_error const& e) {
			std::cerr << "Error: "<< e.what() << std::endl;
		}
	}
}

std::string	BitcoinExchange::parseDate(std::string const& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		throw std::runtime_error("bad date format => " + date);

	int year = std::strtol(date.substr(0,4).c_str(), NULL, 10);
	int month = std::strtol(date.substr(5,2).c_str(), NULL, 10);
	int day = std::strtol(date.substr(8,2).c_str(), NULL, 10);

	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (year < 2000 || year > 2025)
		throw std::runtime_error("invalid date => " + date);
	if (month < 1 || month > 12)
		throw std::runtime_error("invalid date => " + date);
	if (day < 1 || day > 31)
		throw std::runtime_error("invalid date => " + date);
	if (month == 2) {
		int maxDay = isLeap ? 29 : 28;
		if (day > maxDay)
			throw std::runtime_error("invalid date => " + date);
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			throw std::runtime_error("invalid date => " + date);
	}
	return date;
}

double	BitcoinExchange::parseValue(std::string const& value) const {
	double	val;
	char	extra;

	std::istringstream s(value);
	if (!(s >> val) || (s >> extra))
		throw std::runtime_error("invalid value input => " + value);
	if (val < 0)
		throw std::runtime_error("not a positive value => " + value);
	return val;
}

double	BitcoinExchange::getRateOnDate(std::string const& date) const {
	std::map<std::string, double>::const_iterator ref;

	ref = database_.lower_bound(date);
	if (ref == database_.begin())
		throw std::runtime_error(date + " is prior to DB earliest entry");
	if (ref->first == date || ref == database_.end())
		return ref->second;
	else
		return (--ref)->second;
}

void	BitcoinExchange::openFile(std::string const& path, std::ifstream& file) {
	file.close();
	file.clear();
	file.open(path.c_str(), std::ios::in);
	if (file.is_open() == false)
		throw std::runtime_error("failed to open file " + path);
}

bool	BitcoinExchange::isEmptyLine(std::string const& line) {
	if (line.empty()) return true;
	if (line.find_first_not_of(" \t\v\f\r") == std::string::npos) return true;
	return false;
}
