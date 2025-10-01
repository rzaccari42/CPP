/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:55:26 by razaccar          #+#    #+#             */
/*   Updated: 2025/08/25 19:40:02 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <ostream>

int	main() {
	Data data = {.id = 420, .name = "ThinkPad"};
	uintptr_t ptrRaw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(ptrRaw);

	std::cout << "=== object ===" << std::endl;
	std::cout << "address: " << &data << std::endl;
	std::cout << "id: " << data.id << std::endl;
	std::cout << "name: " << data.name << std::endl;
	std::cout << std::endl;

	std::cout << "serialized pointer (uintptr_t): " << ptrRaw << std::endl;
	std::cout << std::endl;

	std::cout << "=== object via deserialized uintptr_t ===" << std::endl;
	std::cout << "address: " << ptr << std::endl;
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << std::endl;

	if (ptr == &data)
		std::cout << "deserialized pointer points to the original" << std::endl;
	else
		std::cout << "deserialized pointer is different from original" << std::endl;
}
