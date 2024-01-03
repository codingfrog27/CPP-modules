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

NAME = PhoneBook

CC = g++

Wflags = -Wall -Wextra -Werror -g

VERSION_FLAG = -std=c++17

SOURCES = PhoneBook.cpp main.cpp
OFILES	:=	$(SOURCES:.cpp=.o)

INCLUDE_DIR = include/

#-----colours----

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#-----------------

NAME: $(SOURCES) $(OFILES)
	@$(CC) $(Wflags) $(VERSION_FLAG) $(SOURCES) -I $(INCLUDE_DIR) -o $(NAME)
	@printf "$(COLOUR_BLUE)$(NAME) $(COLOUR_GREEN) Compiled!\n\n$(COLOUR_END)"

%.o : %.cpp
	@$(CC) -c $< $(Wflags) $(VERSION_FLAG) -I $(INCLUDE_DIR) -o $@
	@printf "$(C_GREEN)Compiling $(C_CYAN)$<\n$(C_RESET)"

re: fclean NAME

run: NAME
	@./PhoneBook

clean:
	@rm -rf *.o
	@printf "$(COLOUR_RED)$(NAME) removed \n\n$(COLOUR_END)"
fclean: clean
	@rm -rf $(NAME)


C_RED		= \033[31m
C_LRED		= \x1b[38;2;255;128;128m
C_DRED		= \x1b[38;2;128;0;0m
C_LORANGE	= \033[38;5;208m
C_ORANGE	= \033[38;5;208m
C_DORANGE	= \x1b[38;2;128;64;0m
C_LYELLOW	= \x1b[38;2;255;255;128m
C_YELLOW	= \x1b[38;2;255;255;0m
C_DYELLOW	= \x1b[38;2;128;128;0m
C_LCHRT		= \x1b[38;2;192;255;128m
C_CHRT		= \x1b[38;2;128;255;0m
C_DCHRT		= \x1b[38;2;64;128;0m
C_LGREEN	= \x1b[38;2;128;255;128m
C_GREEN		= \033[32m
C_LCYAN		= \033[38;5;87m
C_CYAN		= \033[38;5;87m
C_DCYAN		= \x1b[38;2;0;128;128m
C_LAZURE	= \x1b[38;2;0;192;255m
C_AZURE		= \x1b[38;2;0;128;255m
C_DAZURE	= \x1b[38;2;0;64;128m
C_LBLUE		= \x1b[38;2;128;128;255m
C_BLUE		= \x1b[38;2;0;0;255m
C_DBLUE		= \x1b[38;2;0;0;128m
C_LVIOLET	= \x1b[38;2;192;0;255m
C_VIOLET	= \x1b[38;2;128;0;255m
C_DVIOLET	= \x1b[38;2;64;0;255m

C_RESET	= $(shell tput sgr0)
C_BOLD	=$(shell tput bold)
