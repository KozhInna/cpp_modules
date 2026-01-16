# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 14:25:34 by ikozhina          #+#    #+#              #
#    Updated: 2026/01/16 14:38:43 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bureaucrat

CXX := c++

CXXFLAGS := -Werror -Wall -Wextra -std=c++17

SRCS := Bureaucrat.cpp main.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re