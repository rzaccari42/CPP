/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 22:49:28 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/01 01:14:00 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int val) {
	return std::find(container.begin(), container.end(), val);
}

template <typename T>
typename T::const_iterator easyfind(T const& container, int val) {
	return std::find(container.begin(), container.end(), val);
}
