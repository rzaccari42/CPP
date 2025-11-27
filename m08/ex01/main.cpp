/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:29:48 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 02:53:10 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <iostream>

int main() {
{
	Span sp(0);

	try {
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	} catch (std::exception const& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
}
{
    Span sp(5);

    int a[] = {42, 69, -100};
    std::vector<int> v;
    v.push_back(15);
    v.push_back(-50);

    std::vector<int> empty;

    try {
		sp.addNumber(a, a + 3);
		sp.addNumber(v.begin(), v.end());
		sp.addNumber(empty.begin(), empty.end());
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
		return 1;
    }

    try {
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan()  << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\nException caught: " << e.what() << std::endl;
		return 1;
    }
	return 0;
}
{
    Span sp(10);

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
}
