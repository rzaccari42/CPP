/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:07:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 02:09:45 by razaccar         ###   ########.fr       */
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

        bool	operator>(const Fixed& rhs);
        bool	operator<(const Fixed& rhs);
        bool	operator>=(const Fixed& rhs);
        bool	operator<=(const Fixed& rhs);
        bool	operator==(const Fixed& rhs);
        bool	operator!=(const Fixed& rhs);
        Fixed&	operator=(const Fixed& rhs);
        Fixed	operator+(const Fixed& rhs);
        Fixed	operator-(const Fixed& rhs);
        Fixed	operator*(const Fixed& rhs);
        Fixed	operator/(const Fixed& rhs);
        Fixed&	operator++();
        Fixed	operator++(int);
        Fixed&	operator--();
        Fixed	operator--(int);
		friend std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

	private:
		int					rawBits_;
		static const int	fBits_ = 8;
};
