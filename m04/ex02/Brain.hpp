/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:16:58 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/30 21:12:07 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();

        Brain& operator=(const Brain& rhs);

		void				setIdea(size_t index, const std::string& idea);
		const std::string&	getIdea(size_t index) const;
	private:
		std::string ideas_[100];
};
