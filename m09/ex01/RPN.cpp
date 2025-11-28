/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 00:22:53 by razaccar          #+#    #+#             */
/*   Updated: 2025/09/21 22:42:23 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <climits>
#include <string>
#include <sstream>
#include <stack>
#include <algorithm>
#include <stdexcept>

std::stringstream errMessage;

static int	apply(char op, int l, int r) {
	switch (op) {
		case '+': 
			return l + r;
		case '-':
			return l - r;
		case '*':
			return l * r;	
		case '/':
			if (r == 0)
				throw std::runtime_error("division by zero");
			return l / r;	
	}
	return INT_MAX;
}

int	evalRPN(std::string const& expression) {
	std::stack<int>				expr;
	std::string::const_iterator token;
	std::string					op("+-*/");

	for (token = expression.begin(); token != expression.end(); ++token) {
		if (std::isdigit(*token))
			expr.push(*token - 48);
		else if (std::isspace(*token))
			continue;
		else if (std::find(op.begin(), op.end(), *token) != op.end()) {
			if (expr.size() < 2) 
				throw std::runtime_error("not a valid RPN expression");
			int r = expr.top(); expr.pop();
			int l = expr.top(); expr.pop();
			expr.push(apply(*token, l, r));
		}
		else 
			throw std::runtime_error("invalid token found");
	}
	if (expr.size() != 1)
		throw std::runtime_error("not a valid RPN expression");
	return expr.top();
} 
