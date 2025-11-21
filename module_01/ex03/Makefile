# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 11:39:08 by ikozhina          #+#    #+#              #
#    Updated: 2025/11/21 09:22:23 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := violence

CC := c++

CFLAGS := -Werror -Wextra -Wall -std=c++17

SRCS := main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJS := $(SRCS:.cpp=.o)

DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean