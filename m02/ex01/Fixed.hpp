/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:07:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 09:00:39 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>

class Fixed {
	public:
		Fixed();
        Fixed(const Fixed& other);
        Fixed(const int& i);
        Fixed(const float& f);
        ~Fixed();

        Fixed& operator=(const Fixed& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

		void	setRawBits(const int raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int					rawBits_;
		static const int	fBits_ = 8;
};
