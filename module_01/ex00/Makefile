# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 09:59:14 by ikozhina          #+#    #+#              #
#    Updated: 2025/11/12 11:26:21 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := zombie

CC := g++

CFLAGS := -Werror -Wextra -Wall -std=c++17

SRCS := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run



