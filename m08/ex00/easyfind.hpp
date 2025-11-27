/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:49:28 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 02:14:02 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator	easyfind(T& container, int val) {
	if (container.empty()) throw std::logic_error("cannot use easyfind on empty container");
	return std::find(container.begin(), container.end(), val);
}

