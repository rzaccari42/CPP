/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 01:18:47 by razaccar          #+#    #+#             */
/*   Updated: 2025/11/24 17:26:19 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void run(int argc, char **argv);

	private:
		typedef unsigned int value_type;
		typedef std::vector<value_type> Vector;
		typedef std::deque<value_type> Deque;

		struct Pair {
			value_type small;
			value_type big;
		};

		static bool parseArguments(int argc, char **argv, Vector &out);
		static bool isPositiveInteger(const std::string &s);
		static void printSequence(const Vector &seq, const std::string &prefix);

		static void sortVector(Vector &v);
		static void sortDeque(Deque &d);

		static void mergeInsertSortVector(Vector &v);
		static void mergeInsertSortDeque(Deque &d);

		static void binaryInsertVector(Vector &v, value_type value);
		static void binaryInsertDeque(Deque &d, value_type value);
};

#endif
