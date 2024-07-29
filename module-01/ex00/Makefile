# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mde-cloe <mde-cloe@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/10 18:17:45 by mde-cloe      #+#    #+#                  #
#    Updated: 2023/04/10 18:17:45 by mde-cloe      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = Zombie

CC = g++

Wflags = -Wall -Wextra -Werror -g

VERSION_FLAG = -std=c++17

SOURCES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OFILES	:=	$(SOURCES:.cpp=.o)

INCLUDE_DIR = Accounts.hpp

#-----colours----

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#-----------------

$(NAME): $(SOURCES) $(OFILES)
	@$(CC) $(Wflags) $(VERSION_FLAG) $(SOURCES) -I $(INCLUDE_DIR) -o $(NAME)
	@printf "$(COLOUR_BLUE)$(NAME) $(COLOUR_GREEN) Compiled!\n\n$(COLOUR_END)"

%.o : %.cpp
	@$(CC) -c $< $(Wflags) $(VERSION_FLAG) -I $(INCLUDE_DIR) -o $@
	@printf "$(C_GREEN)Compiling $(C_CYAN)$<\n$(C_RESET)"

re: fclean $(NAME)

run: $(NAME)
	@./$(NAME)

clean:
	@rm -rf *.o
	@printf "$(COLOUR_RED)$(NAME) removed \n\n$(COLOUR_END)"
fclean: clean
	@rm -rf $(NAME)

C_RESET	= $(shell tput sgr0)
C_BOLD	=$(shell tput bold)
