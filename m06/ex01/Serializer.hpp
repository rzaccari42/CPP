/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:19:45 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/29 17:24:31 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include <string>

struct Data {
	int			id;
	std::string	name;
};

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const& other);
		~Serializer();

		Serializer&	operator=(Serializer const& rhs);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
