/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 02:57:34 by razaccar          #+#    #+#             */
/*   Updated: 2025/10/06 12:57:26 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : capacity_(N) {}

Span::Span(Span const& other) : 
	container_(other.container_), capacity_(other.capacity_) {}

Span::~Span() {}

Span& Span::operator=(Span const& rhs) {
	if (this == &rhs)
		return *this;
	container_ = rhs.container_;
	capacity_ = rhs.capacity_;
	return *this;
}

void Span::addNumber(int nbr) {
	if (container_.size() == capacity_) {
		throw std::length_error("Span capacity overflow");
		return;
	}
	container_.push_back(nbr);
}

int Span::shortestSpan() {
	if (container_.size() < 2) {
		throw std::logic_error("minimum of 2 numbers needed to compute span");
		return -1;
	}

	int	shortest = INT_MAX;
	std::vector<int>::iterator it;
	std::vector<int>::iterator current;
	for (current = container_.begin(); current < container_.end(); ++current) {
		for (it = current + 1; it < container_.end(); ++it) {
			int span = *current - *it;
			if (span < 0) { span *= -1; }
			if (span < shortest) { shortest = span; };
		}
	}
	return shortest;
}

int Span::longestSpan() {
	if (container_.size() < 2) {
		throw std::logic_error("minimum of 2 numbers needed to compute span");
		return -1;
	}

	int	longest = INT_MIN;
	std::vector<int>::iterator it;
	std::vector<int>::iterator current;
	for (current = container_.begin(); current <= container_.end(); ++current) {
		for (it = current + 1; it < container_.end(); ++it) {
			int span = *current - *it;
			if (span < 0) { span *= -1; }
			if (span > longest) { longest = span; };
		}
	}
	return longest;
}
