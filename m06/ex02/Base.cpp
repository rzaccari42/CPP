/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 19:42:51 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/25 19:10:32 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base() {
	std::cout << "object deleted" << std::endl;
}

Base*	generate() {
	srand(time(NULL));
	int rng = rand() % 3;
	Base* ptr;
	switch (rng) {
		case 0:
			ptr = new A();
			break;
		case 1:
			ptr = new B();
			break;
		case 2:
			ptr = new C();
			break;
	}
	return ptr;
}

void	identify(Base* ptr) {
	if (dynamic_cast<A*>(ptr)) {
		std::cout << "pointer to derived A class" << std::endl;
	} else if (dynamic_cast<B*>(ptr)) {
		std::cout << "pointer to derived B class" << std::endl;
	} else if (dynamic_cast<C*>(ptr)) {
		std::cout << "pointer to derived C class" << std::endl;
	}
}

void	identify(Base& ptr) {
	if (dynamic_cast<A*>(&ptr)) {
		std::cout << "reference to derived A class" << std::endl;
	} else if (dynamic_cast<B*>(&ptr)) {
		std::cout << "reference to derived B class" << std::endl;
	} else if (dynamic_cast<C*>(&ptr)) {
		std::cout << "reference to derived C class" << std::endl;
	}
}
