/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:06:44 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/29 13:27:44 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int main( void ) {
// 	Fixed		a;
// 	Fixed		b(42.42f);
// 	Fixed		c(20);
// 	Fixed		d(-1);
// 	Fixed		max(INT_MAX / 256);
// 	Fixed		min(INT_MIN / 256);
// 	Fixed		overflow(INT_MAX);
//
// 	std::cout << b << std::endl;
// 	std::cout << max.toInt() << std::endl;
// 	std::cout << min.toInt() << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	std::cout << --a << std::endl;
// 	std::cout << a.toInt() << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	std::cout << max.toInt() << std::endl;
// 	max++; 
// 	std::cout << max.toInt() << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	std::cout << b + c << std::endl;
// 	std::cout << c - b << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	std::cout << b * c << std::endl;
// 	std::cout << b / c << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	std::cout << c / 0 << std::endl;
// 	std::cout << b * 1000000 << std::endl;
// 	std::cout << min / d << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	if (b < c)
// 		std::cout << b.toFloat() << " is smaller than " << c.toFloat() << std::endl;
// 	else
// 		std::cout << b.toFloat() << " is greather than " << c.toFloat() << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	if (b != c)
// 		std::cout << "numbers are different" << std::endl;
// 	else
// 		std::cout << "numbers are same" << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	std::cout << "Max is : " << Fixed::max(b, c) << std::endl;
// 	std::cout << "--------------------------" << std::endl;
// 	return 0;
// }
