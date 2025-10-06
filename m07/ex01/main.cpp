/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:15:11 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/29 23:19:41 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T const& data) {
	std::cout << data << std::endl;
}

template <typename T>
void increment(T& data) {
	data++;
}

void incrementInt(int& data) {
	data++;
}

int	main() {
	// std::string arr[] = {"hello", "world", "42"};
	int arr[] = {22, 42, 420};
	int const carr[] = {22, 42, 420};

	iter(arr, 3, increment);
	iter(arr, 3, print);
	iter(carr, 3, print);
}
