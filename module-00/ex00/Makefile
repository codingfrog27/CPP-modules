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

NAME = megaphone

CC = c++

Wflags = -Wall -Wextra -Werror -fsanitize=address

OLDCPPFLAG = -std=c++98

SOURCES = megaphone.cpp

#-----colours----

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

#-----------------

NAME: $(SOURCES)
	@$(CC) $(Wflags) $(SOURCES) -o $(NAME)
	@printf "$(COLOUR_BLUE)megaphone$(COLOUR_GREEN) Compiled!\n\n$(COLOUR_END)"

re: fclean NAME

run: NAME
	@./megaphone hi I am testing uwu
fclean:
	@rm $(NAME)
	@printf "$(COLOUR_RED) Megaphone removed \n\n$(COLOUR_END)"