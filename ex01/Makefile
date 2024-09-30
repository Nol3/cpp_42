# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 12:59:49 by alcarden          #+#    #+#              #
#    Updated: 2024/09/30 16:51:39 by alcarden         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
FILES = src/phonebook.cpp src/phonebook.hpp 
OBJS = $(FILES:.cpp=.o)
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

$(NAME): $(OBJS)
	@c++ -Wall -Wextra -Werror $(FILES) -o $(NAME)
	@echo "$(GREEN) Program compiled! $(END)"

$(OBJS): $(FILES)
	@c++ -Wall -Wextra -Werror -c $< -o $@
	@echo "$(GREEN) Objects compiled! $(END)"

fclean:
	@rm -f $(NAME) $(OBJS)
	@echo "$(RED) Program and objects deleted! $(END)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED) Objects deleted! $(END)"

re: fclean $(NAME)

.PHONY: clean fclean