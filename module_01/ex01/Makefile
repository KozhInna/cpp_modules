# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 13:41:02 by ikozhina          #+#    #+#              #
#    Updated: 2025/11/21 09:22:08 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := zombies

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++17

SRCS := main.cpp Zombie.cpp zombieHorde.cpp

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