# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 20:56:39 by razaccar          #+#    #+#              #
#    Updated: 2025/06/20 12:13:37 by razaccar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp 
OBJS = ${SRCS:.cpp=.o}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: clean all
