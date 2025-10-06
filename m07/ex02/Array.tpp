/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 22:48:10 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/01 00:31:25 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstddef>

template <typename T>
Array<T>::Array() : size_(0) {
	array_ = NULL;
};

template <typename T>
Array<T>::Array(unsigned int n) : size_(n) {
	array_ = size_ > 0 ? new T[size_]() : NULL;
};

template <typename T>
Array<T>::Array(Array const& other) : size_(other.size_) {
	if (size_ < 1) {
		array_ = NULL;
		return;
	}
	array_ = new T[size_]() ;
	for (size_t i = 0; i < size_; i++)
		array_[i] = other.array_[i];
};

template <typename T>
Array<T>::~Array() {
	delete[] array_;
};

template <typename T>
Array<T>&	Array<T>::operator=(Array const& rhs) {
	if (this == &rhs)
		return *this;

	size_ = rhs.size_;
	if (size_ < 1) {
		array_ = NULL;
		return *this;
	}
	if (array_) delete[] array_;
	array_ = new T[size_]();
	for (size_t i = 0; i < size_; i++)
		array_[i] = rhs.array_[i];
	return *this;
};

template <typename T>
T&	Array<T>::operator[](size_t index) {
	if (!(this->array_) || index >= size_) throw (OutOfBoundsException());
	return array_[index];
};

template <typename T>
T const&	Array<T>::operator[](size_t index) const {
	if (!(this->array_) || index >= size_) throw (OutOfBoundsException());
	return array_[index];
};

template <typename T>
size_t	Array<T>::size() const {
	return size_;
};

template <typename T>
T*	Array<T>::getArray() const {
	return array_;
}
