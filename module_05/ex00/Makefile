# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozhina <ikozhina@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/25 10:26:12 by ikozhina          #+#    #+#              #
#    Updated: 2026/03/25 10:28:15 by ikozhina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bureaucrat

CXX := c++

CXXFLAGS := -Werror -Wextra -Wall -std=c++17

SRCS := main.cpp Bureaucrat.cpp
OBJDIR := obj
OBJS := $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re