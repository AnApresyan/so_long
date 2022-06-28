# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 21:36:19 by aapresya          #+#    #+#              #
#    Updated: 2022/06/28 21:36:20 by aapresya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
SRCS	= $(wildcard *.c)
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -O3 -Wall -Wextra -Werror
RM		= rm -rf

all: $(NAME)

${NAME}: ${OBJS}
	@echo [so_long] Compiling mlx...
	@$(MAKE) -C ./mlx
	@echo [so_long] Compiling libft...
	@$(MAKE) -C ./libft
	@mv mlx/libmlx.dylib .
	@echo [so_long] Compiling so_long...
	@${CC} ${OBJS} ${CFLAGS} ${MLX} ./libft/libft.a libmlx.dylib -o ${NAME}
	@echo [so_long] so_long successfully compiled. Run ./so_long \*.ber to read from a map. 

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} libmlx.dylib

norme:
	@norminette -R CheckForbiddenSourceHeader *.c *.h libft/*.c libft/*.h
	
bonus: all

re: fclean all

.PHONY: clean fclean re all bonus
