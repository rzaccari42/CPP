/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:53:57 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 22:12:33 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ANIMALS_NB 6

int main()
{
	AAnimal		a;
	AAnimal*	animals[ANIMALS_NB];	

	for (size_t i = 0; i < ANIMALS_NB; ++i) {
		animals[i] = new Dog();	
		i++;
		animals[i] = new Cat();	
	}

	for (size_t i = 0; i < ANIMALS_NB; ++i)
		animals[i]->makeSound();

	for (size_t i = 0; i < ANIMALS_NB; ++i)
		delete animals[i];
}

// int	main() {
// 	Dog original;
// 	original.getBrain()->setIdea(0, "Chase the cat");
// 	original.getBrain()->setIdea(1, "Dig a hole");
//
// 	Dog copy = original; // Copy constructor (deep copy!)
//
// 	std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
// 	std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
//
// 	// Modify original
// 	original.getBrain()->setIdea(0, "Sleep");
//
// 	std::cout << "After change - Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
// 	std::cout << "After change - Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
// }
//
