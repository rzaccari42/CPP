/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:39:31 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/01 00:37:09 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>
#include <iostream>

template <typename T>
void print(T const& data) {
	std::cout << data << std::endl;
}

int main() {
	try {
		Array<int> arr(3);
		arr[0] = 4;
		arr[1] = 69;
		arr[2] = 420;

		Array<int> other_arr;
		other_arr = arr;
		other_arr[1] = 42;

		Array<int> copy_arr(other_arr);
		copy_arr[0] = 42;

		iter(arr.getArray(), arr.size(), print);
		std::cout << std::endl;
		iter(other_arr.getArray(), other_arr.size(), print);
		std::cout << std::endl;
		iter(copy_arr.getArray(), copy_arr.size(), print);
	} catch (std::exception const& e) {
		std::cerr << "exception caught: " << e.what() << std::endl;
		return 1;
	}
	
	Array<int> empty_arr;
	iter(empty_arr.getArray(), empty_arr.size(), print);
}
