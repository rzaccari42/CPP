/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:07:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/14 12:09:33 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
	public:
		Fixed(void);
        Fixed(const Fixed& fixed);
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed(void);
        Fixed& operator=(const Fixed& fixed);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int					val_;
		static const int	fBits = 8;
};
