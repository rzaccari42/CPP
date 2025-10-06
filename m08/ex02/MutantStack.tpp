/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:58:47 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/06 20:47:41 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <stack>

template<typename T, class C>
MutantStack<T, C>::MutantStack() : std::stack<T, C>() {}

template<typename T, class C>
MutantStack<T, C>::MutantStack(MutantStack const& other)
	: std::stack<T, C>(other) {}

template<typename T, class C>
MutantStack<T, C>::~MutantStack() {}

template<typename T, class C>
MutantStack<T, C>&	MutantStack<T, C>::operator=(MutantStack const& rhs) {
	if (this != &rhs)
		std::stack<C, T>::operator=(rhs);
	return *this;
}

template<typename T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::begin() {
	return this->c.begin();
}

template<typename T, class C>
typename MutantStack<T, C>::iterator	MutantStack<T, C>::end() {
	return this->c.end();
}

template<typename T, class C>
typename MutantStack<T, C>::const_iterator	MutantStack<T, C>::begin() const {
	return this->c.begin();
}

template<typename T, class C>
typename MutantStack<T, C>::const_iterator	MutantStack<T, C>::end() const {
	return this->c.end();
}
