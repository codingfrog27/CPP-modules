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

NAME := polymorphism

CC = c++

Wflags = -Wall -Wextra -Werror -g -fsanitize=address

INCLUDE = -I include/

VERSION_FLAG = -std=c++20

SOURCES = NicePrint.cpp Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
OFILES	:=	$(SOURCES:.cpp=.o)

#-----colours----

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#-----------------

$(NAME): $(SOURCES) $(OFILES)
	@$(CC) $(Wflags) $(INCLUDE) $(VERSION_FLAG) $(OFILES) -o $(NAME)
	@printf "$(COLOUR_BLUE)$(NAME) $(COLOUR_GREEN) Compiled!\n\n$(COLOUR_END)"

%.o : %.cpp
	@$(CC) -c $< $(Wflags) $(INCLUDE) $(VERSION_FLAG) -o $@
	@printf "$(C_GREEN)Compiling $(C_CYAN)$<\n$(C_RESET)"

re: fclean $(NAME)

run: $(NAME)
	@rm -rf *.o
	@./$(NAME)

clean:
	@rm -rf *.o
	@printf "$(COLOUR_RED)$(NAME) removed \n\n$(COLOUR_END)"
fclean: clean
	@rm -rf $(NAME)

C_RESET	= $(shell tput sgr0)
C_BOLD	=$(shell tput bold)
