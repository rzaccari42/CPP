/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:07:52 by razaccar          #+#    #+#             */
/*   Updated: 2025/06/27 09:01:10 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
	public:
		Fixed();
        Fixed(const Fixed& other);
        ~Fixed();
        Fixed& operator=(const Fixed& rhs);

		int	 getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int					rawBits_;
		static const int	fBits = 8;
};
