/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:53:31 by razaccar          #+#    #+#             */
/*   Updated: 2025/05/09 15:59:55 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
    for (size_t arg_i = 1; arg_i < (size_t)argc; ++arg_i) {
        std::string str = argv[arg_i];
        for (size_t str_i = 0; str_i < str.length(); ++str_i) {
            if (str[str_i] >= 'a' && str[str_i] <= 'z') {
                str[str_i] -= 'a' - 'A';
            }
        }
        std::cout << str;
    }
    std::cout << std::endl;
    return (0);
}
