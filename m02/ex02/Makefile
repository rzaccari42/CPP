# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razaccar <razaccar@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 20:56:39 by razaccar          #+#    #+#              #
#    Updated: 2025/06/22 23:26:16 by razaccar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Maintenant_on_peut_parler

SRCS = main.cpp Fixed.cpp 
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

re: fclean all
