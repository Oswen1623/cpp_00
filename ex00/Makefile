# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucinguy <lucinguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 23:03:37 by lucinguy          #+#    #+#              #
#    Updated: 2026/11/03 00:41:11 by lucinguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= megaphone
C++			:= c++
C++FLAGS	:= -Wall -Wextra -Werror -std=c++98
RM			:= rm -f

SRCS		:= megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	$(C++) $(C++FLAGS) $(SRCS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully!"

clean:
	@:
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
