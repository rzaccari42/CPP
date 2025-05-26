/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 02:37:11 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/24 15:47:06 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <sstream>

std::string load_file(const std::string& filepath)
{
    std::ifstream src(filepath);
    std::ostringstream buf;
    buf << src.rdbuf();
    return buf.str();
}

int	main(int argc, char** argv) {
	(void)argc;
	std::string		fileName = argv[1];

	std::cout << load_file(fileName);
	return 0;
}

// int	main(int argc, char **argv) {
// 	if (argc != 4) return 1; 
//
// 	std::string	fileName = argv[1];
// 	std::string	search = argv[2];
// 	std::string	replace = argv[3];
//
// 	std::ifstream	file(fileName);
// 	fileName += ".replace";
// 	std::ofstream	fileReplace(fileName);
//
// 	if (file.is_open() && fileReplace.is_open()) {
// 		std::stringbuf		buf;
// 		std::stringstream	line;
// 		size_t		searchPos;
// 		size_t		searchSize = search.length();
// 		while (!file.eof()) {
// 			file.getline(buf, std::string::npos);
// 			while ((searchPos = buf.find(search)) != buf.npos) {
// 				line.assign(buf, 0, searchPos - 1);
// 				line += replace;
// 				buf = buf.substr(searchPos + searchSize);
// 			}
// 			fileReplace << line << '\n';
// 			line.clear();
// 		}
// 		file.close();
// 	}
// }
