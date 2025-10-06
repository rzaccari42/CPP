/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:39:40 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/30 22:57:48 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <cstdlib>
#include <exception>

template <typename T> 
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const& other);
		~Array();

		Array&		operator=(Array const& rhs);
		T&			operator[](size_t index);
		T const&	operator[](size_t index) const;

		T*		getArray() const; 
		size_t	size() const;

		class OutOfBoundsException;

	private:
		T*				array_;
		unsigned int	size_;
};

template <typename T> 
class Array<T>::OutOfBoundsException : public std::exception {
	public:
		const char* what() const throw() {
			return  "trying to access out of bounds memory";
		}
};

#include "Array.tpp"

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
