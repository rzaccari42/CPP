/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:21:34 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/25 00:11:58 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other) {}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::isPositiveInteger(const std::string &s)
{
	if (s.empty())
		return false;
	for (size_t i = 0; i < s.size(); ++i) {
		if (s[i] < '0' || s[i] > '9')
		return false;
	}
	return true;
}

bool PmergeMe::parseArguments(int argc, char **argv, Vector &out)
{
	for (int i = 1; i < argc; ++i) {
		std::string token(argv[i]);
		if (!isPositiveInteger(token))
			return false;

		std::istringstream iss(token);
		long value = 0;
		iss >> value;
		if (iss.fail() || !iss.eof() || value <= 0)
			return false;
		if (value > static_cast<long>(~static_cast<unsigned int>(0)))
			return false;
		out.push_back(static_cast<value_type>(value));
	}
	return !out.empty();
}


void PmergeMe::printSequence(const Vector &seq, const std::string &prefix)
{
	std::cout << prefix;
	for (Vector::const_iterator it = seq.begin(); it != seq.end(); ++it) {
		std::cout << *it;
		if (it + 1 != seq.end())
		std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::binaryInsertVector(Vector &v, value_type value)
{
	Vector::size_type left = 0;
	Vector::size_type right = v.size();

	while (left < right) {
		Vector::size_type mid = left + (right - left) / 2;
		if (v[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	v.insert(v.begin() + static_cast<Vector::difference_type>(left), value);
}

void PmergeMe::binaryInsertDeque(Deque &d, value_type value)
{
	Deque::size_type left = 0;
	Deque::size_type right = d.size();

	while (left < right) {
		Deque::size_type mid = left + (right - left) / 2;
		if (d[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	d.insert(d.begin() + static_cast<Deque::difference_type>(left), value);
}


void PmergeMe::mergeInsertSortVector(Vector &v)
{
	const Vector::size_type n = v.size();
	if (n < 2)
		return;

	// Step 1: build pairs (small, big)
	std::vector<Pair> pairs;
	pairs.reserve(n / 2);

	value_type stray = 0;
	bool hasStray = false;

	Vector::size_type i = 0;
	for (; i + 1 < n; i += 2) {
		value_type a = v[i];
		value_type b = v[i + 1];
		Pair p;
		if (a <= b) {
			p.small = a;
			p.big = b;
		}
		else {
			p.small = b;
			p.big = a;
		}
		pairs.push_back(p);
	}

	if (i < n) {
		stray = v[i];
		hasStray = true;
	}

	// Step 2: build main chain from big elements using recursion
	Vector mainChain;
	mainChain.reserve(pairs.size());
	for (std::vector<Pair>::size_type j = 0; j < pairs.size(); ++j)
		mainChain.push_back(pairs[j].big);

	mergeInsertSortVector(mainChain);

	// Step 3: insert the small elements using binary insertion
	// First insert the small element of the first pair into mainChain
	if (!pairs.empty())
		binaryInsertVector(mainChain, pairs[0].small);

	// Insert the remaining small elements
	for (std::vector<Pair>::size_type j = 1; j < pairs.size(); ++j) {
		binaryInsertVector(mainChain, pairs[j].small);
	}

	// Step 4: insert stray element if any
	if (hasStray)
		binaryInsertVector(mainChain, stray);

	v.swap(mainChain);
}


void PmergeMe::mergeInsertSortDeque(Deque &d)
{
	const Deque::size_type n = d.size();
	if (n < 2u)
		return;

	std::vector<Pair> pairs;
	pairs.reserve(n / 2u);

	value_type stray = 0;
	bool hasStray = false;

	Deque::size_type i = 0;
	for (; i + 1u < n; i += 2u) {
		value_type a = d[i];
		value_type b = d[i + 1u];
		Pair p;
		if (a <= b) {
			p.small = a;
			p.big = b;
		}
		else {
			p.small = b;
			p.big = a;
		}
		pairs.push_back(p);
	}
	if (i < n) {
		stray = d[i];
		hasStray = true;
	}
	// main chain built from big elements
	Deque mainChain;
	mainChain.resize(0);
	for (std::vector<Pair>::size_type j = 0; j < pairs.size(); ++j)
		mainChain.push_back(pairs[j].big);

	mergeInsertSortDeque(mainChain);

	if (!pairs.empty())
		binaryInsertDeque(mainChain, pairs[0].small);

	for (std::vector<Pair>::size_type j = 1; j < pairs.size(); ++j) {
		binaryInsertDeque(mainChain, pairs[j].small);
	}

	if (hasStray)
		binaryInsertDeque(mainChain, stray);

	d.swap(mainChain);
}


void PmergeMe::sortVector(Vector &v)
{
	mergeInsertSortVector(v);
}


void PmergeMe::sortDeque(Deque &d)
{
	mergeInsertSortDeque(d);
}


void PmergeMe::run(int argc, char **argv)
{
	Vector values;
	if (!parseArguments(argc, argv, values))
		throw std::runtime_error("invalid arguments");

	printSequence(values, "Before: ");

	Vector vec(values.begin(), values.end());
	Deque deq(values.begin(), values.end());

	std::clock_t startVec = std::clock();
	sortVector(vec);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	sortDeque(deq);
	std::clock_t endDeq = std::clock();
	
	printSequence(vec, "After: ");

	const double vecTimeUs = static_cast<double>((endVec - startVec) * 1000000.0) / static_cast<double>(CLOCKS_PER_SEC);
	const double deqTimeUs = static_cast<double>((endDeq - startDeq) * 1000000.0) / static_cast<double>(CLOCKS_PER_SEC);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(5);

	std::cout << "Time to process a range of "
	<< values.size() << " elements with std::vector : "
	<< vecTimeUs << " us" << std::endl;

	std::cout << "Time to process a range of "
	<< values.size() << " elements with std::deque : "
	<< deqTimeUs << " us" << std::endl;
}
