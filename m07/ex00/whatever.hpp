/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 02:13:03 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/19 17:56:22 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T& x, T& y) {
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T& min(T& x, T& y) {
	if (x == y)
		return y;
	if (x < y)
		return x;
	return y;
}

template<typename T>
T& max(T& x, T& y) {
	if (x == y)
		return y;
	if (x > y)
		return x;
	return y;
}

