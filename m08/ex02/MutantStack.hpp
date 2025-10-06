/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:46:04 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/06 14:12:41 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <stack>

template<typename T, class C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
	public:
		typedef typename C::iterator iterator;
		typedef typename C::const_iterator const_iterator;

		MutantStack();
		MutantStack(MutantStack const& other);
		~MutantStack();

		MutantStack&	operator=(MutantStack const& rhs);

		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

#include "MutantStack.tpp"
