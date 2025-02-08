NAME = replace
SRC_DIR = src
FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(FILES:.cpp=.o)
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

$(NAME): $(OBJS)
	@c++ -Wall -Wextra -Werror $(FILES) -o $(NAME)
	@echo "$(GREEN) Program compiled! $(END)"

$(OBJS): $(FILES)
	@c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@
	@echo "$(GREEN) Objects compiled! $(END)"

fclean:
	@rm -f $(NAME) $(OBJS)
	@echo "$(RED) Program and objects deleted! $(END)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED) Objects deleted! $(END)"

re: fclean $(NAME)

.PHONY: clean fclean
