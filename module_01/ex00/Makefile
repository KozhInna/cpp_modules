# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 09:59:14 by ikozhina          #+#    #+#              #
#    Updated: 2025/11/21 09:21:47 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := zombie

CC := c++

CFLAGS := -Werror -Wextra -Wall -std=c++17

SRCS := main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJS := $(SRCS:.cpp=.o)

HEADER := Zombie.hpp

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

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run



