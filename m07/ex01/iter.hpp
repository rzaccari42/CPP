/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:15:24 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/01 00:38:58 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T>
void iter(T* arr, size_t lenght, void (*f)(T&)) {
	if (!arr) return;
	for (size_t i = 0; i < lenght; ++i) {
		f(arr[i]);
	}
}

template <typename T>
void iter(T const* arr, size_t lenght, void (*f)(T const&)) {
	if (!arr) return;
	for (size_t i = 0; i < lenght; ++i) {
		f(arr[i]);
	}
}
