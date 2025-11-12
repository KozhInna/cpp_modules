# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 11:24:53 by ikozhina          #+#    #+#              #
#    Updated: 2025/11/03 10:49:18 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := phonebook

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++17

SRCS := main.cpp Contact.cpp PhoneBook.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re