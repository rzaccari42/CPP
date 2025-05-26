/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:01:00 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/13 21:12:21 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main() {
	std::string		string("HI THIS IS BRAIN");
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;
	// address
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;
	// value
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
