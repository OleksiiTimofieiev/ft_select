# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 12:27:52 by otimofie          #+#    #+#              #
#    Updated: 2019/03/22 12:38:37 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_select

CORE			= main.c \
			
SRCS        	= $(addprefix srcs/, $(CORE))

CFLAGS			= -Wall -Wextra -Werror
OBJECTS 		= $(SRCS:.c=.o)
LIB				= ./libft.a
INC				= ./includes/ft_select.h

#colors
RESET			= \033[m
RED         	= \033[1;31m
GREEN       	= \033[01;38;05;46m
YELLOW      	= \033[01;38;05;226m
BLUE        	= \033[03;38;05;21m
VIOLET      	= \033[01;38;05;201m
CYAN        	= \033[1;36m
WHITE       	= \033[01;38;05;15m

all: $(NAME)

$(NAME): $(LIB) $(OBJECTS) $(INC)
	@ gcc    $(CFLAGS) -I $(INC) $(SRCS) -L ./libft -lft -o $(NAME)
	@ echo  "$(YELLOW) : OK$(RESET)"

$(LIB):
	@ echo  "$(GREEN)Compiling: $(WHITE)libft$(RESET)$(YELLOW) : $(RESET)\c)"
	@ make -C ./libft
	@ echo  "$(GREEN)Compiling: $(WHITE)$(NAME)$(RESET)$(YELLOW) : $(RESET)\c)"

$(OBJECTS): %.o: %.c
	@ gcc -c $(CFLAGS) $< -o $@
	@ echo  "$(YELLOW)█$(RESET)\c)"

clean:
	@ make -C ./libft clean
	@ rm -f $(OBJECTS)

fclean: clean
	@ make -C ./libft fclean
	@ rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re