/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:29:48 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/06 14:30:15 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main() {
{
    Span sp(10000);
	int nbr;
	try {
		while (std::cin.eof() == false) {
			std::cin >> nbr;
			if (std::cin.bad()) {
				std::cerr << "error: failed to parse input" << std::endl;
				return 1;
			}
			sp.addNumber(nbr);
		}
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan()  << std::endl;
	} catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
}
{
    Span sp(6);
	// initializing numbers 
    int a[] = {42, 69, -100};
    std::vector<int> v;
    v.push_back(15);
    v.push_back(-50);

	// adding numbers
    try {
		sp.addNumber(2);
		sp.addNumber(a, a + 3);
		sp.addNumber(v.begin(), v.end());
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
    }

	// computing spans
    try {
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan()  << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
		return 1;
    }
	return 0;
}
}


// int	main() {
// 	Span sp = Span(5);
//
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
//
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
//
// int main() {
// 	Span sp = Span(10);
//
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	
// 	std::cout << "==============" << std::endl;
//
// 	Span sp_2 = sp;
// 	sp_2.addNumber(100);
// 	std::cout << sp_2.shortestSpan() << std::endl;
// 	std::cout << sp_2.longestSpan() << std::endl;
//
// 	std::cout << "==============" << std::endl;
//
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }
