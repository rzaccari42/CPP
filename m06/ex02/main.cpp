/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 22:04:59 by razaccar          #+#    #+#             */
/*   Updated: 2025/08/27 02:00:58 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	Base* random_derived_ptr = generate();
	Base& random_derived_ref = *random_derived_ptr;

	identify(random_derived_ptr);
	identify(random_derived_ref);
	
	delete random_derived_ptr;
}
