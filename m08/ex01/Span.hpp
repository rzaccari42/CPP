/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:30:16 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/06 16:24:02 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class Span {
	public:
		Span(unsigned int N);
		Span(Span const& other);
		~Span();

		Span&	operator=(Span const& rhs);

		void						addNumber(int nbr);
		template<typename It> void	addNumber(It start, It end);
		int							shortestSpan();
		int							longestSpan();
		
	private:
		std::vector<int>	container_;
		unsigned int		capacity_;
};

#include "Span.tpp"
