# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mde-cloe <mde-cloe@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/10 18:17:45 by mde-cloe      #+#    #+#                  #
#    Updated: 2025/07/18 18:41:01 by mde-cloe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := PmergeMe

CC = c++
OBJDIR = objects
SRCDIR := sources
INCLDIR := include

Wflags = -Wall -Wextra -Werror -g -fsanitize=address
VERSION_FLAG = -std=c++20
INCLUDE_FLAG = -I $(INCLDIR)/


HEADERS := $(shell find $(INCLDIR) -name '*.hpp' -o -name '*.tpp')
SOURCES := $(shell find $(SRCDIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES))



#-----colours----

C_GREEN = \033[0;32m
C_RED = \033[0;31m
C_BLUE = \033[0;34m
C_RESET = \033[0m

#-----------------

$(NAME): $(SOURCES) $(OBJECTS)
	@$(CC) $(Wflags) $(INCLUDE_FLAG) $(VERSION_FLAG) $(OBJECTS) -o $(NAME)
	@printf "$(C_BLUE)$(NAME) $(C_GREEN) Compiled!\n\n$(C_RESET)"


$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS) | $(OBJDIR)
	@printf "$(C_GREEN) Compiling $(C_BLUE)$<\n$(C_RESET)"
	@$(CC) -c $< $(Wflags) $(INCLUDE_FLAG) $(VERSION_FLAG) -o $@




$(OBJDIR):
	@mkdir -p $(OBJDIR)

re: fclean $(NAME)

run: $(NAME)
	@./$(NAME) 5 7 9 5380 921 5389 549 54
	@./$(NAME) 1 5 3 2 4


# @./$(NAME) "2 3 4 + -"
# @./$(NAME) "2 48432 * 7897 12 * *"

clean:
	@rm -rf $(OBJDIR)
	@printf "$(C_RED)$(OBJDIR) removed \n\n$(C_RESET)"
fclean: clean
	@rm -rf $(NAME)
	@printf "$(C_RED)$(NAME) removed \n\n$(C_RESET)"
