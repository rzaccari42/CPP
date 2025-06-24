/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 02:37:11 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/24 16:49:32 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>

#define	ERR_ARG "Error: too few arguments"
#define	USAGE	"Usage: ./prog [file] [old] [new]"

std::string	replace(const std::string& line,
					const std::string& oldSeq,
					const std::string& newSeq) {
	std::stringstream newLine;
	size_t pos = 0;
	size_t next = 0;
	while (pos != std::string::npos) {
		if ((next = line.find(oldSeq, pos)) != std::string::npos)
			newLine << line.substr(pos, next - pos) << newSeq;
		else
			newLine << line.substr(pos, std::string::npos);
		pos = (next != std::string::npos) ? next + oldSeq.length() : next;
	}
	return newLine.str();
}

int	main(int argc, char** argv) {
	if (argc != 4) {
		std::cout << ERR_ARG << std::endl << USAGE << std::endl;
		return 1;
	}
	std::string		fileName(argv[1]);
    std::ifstream	inFile(fileName.c_str());
    std::ofstream	outFile((fileName + ".replace").c_str());
    std::string		line;
	if (!inFile.is_open()) {
		std::cout << "error: file " << fileName << " can't be opened" << std::endl;
		return 0;
	}
	while (1) {
		std::getline(inFile, line);
		if (inFile.eof())
			break;
		outFile << replace(line, argv[2], argv[3]) << std::endl;
	}
	return 0;
}

