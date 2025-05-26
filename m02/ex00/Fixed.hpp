/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:07:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/14 02:37:56 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
	public:
		Fixed(void);
        Fixed(const Fixed& fixed);
        ~Fixed(void);
        Fixed& operator=(const Fixed& fixed);

		int	 getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	val_;
		static const int	fBits = 8;
};
