# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/22 12:27:52 by otimofie          #+#    #+#              #
#    Updated: 2019/04/17 17:29:13 by otimofie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_select

CORE			=	main.c \
					linked_list_routines.c \
					init_routines.c \
					init_routines_colors.c \
					init_signals.c \
					error_management.c \
					output_routines.c \
					key_selection.c \
					main_utils.c \
					find_routine.c \
					up_down_links_initialization.c \
					init_row_ends.c \
					up_down_utils.c \
					iteration_helpers.c \
					key_handler_utils.c \
					key_hadlers_with_small_code_size.c \
					key_handlers_small_2.c \
					left_key_handler.c \
					down_key_handler.c \
					key_handler_up.c \

			
SRCS        	= 	$(addprefix srcs/, $(CORE))

CFLAGS			= 	-Wall -Wextra -Werror
OBJECTS 		= 	$(SRCS:.c=.o)
LIB				= 	./libft.a
INC				= 	./includes/

#colors
RESET			= 	\033[m
RED         	= 	\033[1;31m
GREEN       	= 	\033[01;38;05;46m
YELLOW      	= 	\033[01;38;05;226m
BLUE        	= 	\033[03;38;05;21m
VIOLET      	= 	\033[01;38;05;201m
CYAN        	= 	\033[1;36m
WHITE       	= 	\033[01;38;05;15m

all: $(NAME)

$(NAME): $(LIB) $(OBJECTS) $(INC)
	@ gcc    $(CFLAGS) -I$(INC) $(SRCS) -L ./libft -lft -ltermcap -o $(NAME)
	@ echo  "$(YELLOW) : OK$(RESET)"

$(LIB):
	@ echo  "$(GREEN)Compiling: $(WHITE)libft$(RESET)$(YELLOW) : $(RESET)\c)"
	@ make -C ./libft
	@ echo  "$(GREEN)Compiling: $(WHITE)$(NAME)$(RESET)$(YELLOW) : $(RESET)\c)"

$(OBJECTS): %.o: %.c
	@ gcc -c $(CFLAGS) -I$(INC) $< -o $@
	@ echo  "$(YELLOW)█$(RESET)\c)"

clean:
	@ make -C ./libft clean
	@ rm -f $(OBJECTS)

fclean: clean
	@ make -C ./libft fclean
	@ rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re