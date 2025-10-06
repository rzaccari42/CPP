/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:45:47 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/06 20:55:32 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

// int main() {
// 	MutantStack<int, std::vector<int> > s;
// 	s.push(1);
// 	s.push(2);
// 	s.push(4);
// 	s.push(8);
// 	s.push(16);
// 	s.push(32);
//
// 	MutantStack<int, std::vector<int> >::iterator it;
// 	it = s.begin();
// 	std::cout << *(it + 4) << std::endl;
//
// }

int main() {
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "=============================" << std::endl;
	{
		std::list<int> lstack;
		lstack.push_back(5);
		lstack.push_back(17);

		std::cout << lstack.back() << std::endl << std::endl;

		lstack.pop_back();

		std::cout << lstack.size() << std::endl << std::endl;

		lstack.push_back(3);
		lstack.push_back(5);
		lstack.push_back(737);
		lstack.push_back(0);

		std::list<int>::iterator it = lstack.begin();
		std::list<int>::iterator ite = lstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int, std::list<int> > s(lstack);
	}
	return 0;
}
