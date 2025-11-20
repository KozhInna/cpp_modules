# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 20:08:33 by ikozhina          #+#    #+#              #
#    Updated: 2025/11/20 20:30:08 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := harl

CC := g++

CFLAGS := -Werror -Wall -Wextra -std=c++17

SRCS := main.cpp Harl.cpp

HEADER := Harl.hpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re