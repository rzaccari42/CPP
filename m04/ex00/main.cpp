/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:53:57 by razaccar          #+#    #+#             */
/*   Updated: 2025/07/02 19:19:20 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const WrongAnimal* w = new WrongCat();

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	std::cout << w->getType() << " " << std::endl;
	d->makeSound();
	c->makeSound();
	w->makeSound();
	meta->makeSound();
	
	delete meta;
	delete d;
	delete c;
	delete w;
	return 0;
}
