/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:39:45 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/06 12:58:56 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>

template<typename It>
void Span::addNumber(It begin, It end) {
	if (container_.size() + std::distance(begin, end) > capacity_)
		throw std::length_error("Span capacity overflow");
	container_.insert(container_.end(), begin, end);
}
