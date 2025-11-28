/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 20:56:14 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 16:05:49 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(std::string const& database);
		BitcoinExchange(BitcoinExchange const& other);
		~BitcoinExchange();

		BitcoinExchange&	operator=(BitcoinExchange const& rhs);

		std::map<std::string, double> const&	getDatabase() const;

		void	loadDatabase(std::string const& path);
		void	run(std::string const& path) const;

	private:
		std::map<std::string, double>	database_;

		std::string	parseDate(std::string const& date) const;
		double		parseValue(std::string const& value) const;		
		double		getRateOnDate(std::string const& date) const;

		static void	openFile(std::string const& path, std::ifstream& file);
		static bool	isEmptyLine(std::string const& line);
};
