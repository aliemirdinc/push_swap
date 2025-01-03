NAME			= 
NAME_BONUS		= 

LIBFT 			= libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra

REMOVE 			= rm -f

SRCS 			= 

BONUS_SRC 		= 

all:			${NAME} ${LIBFT} 

bonus:			${NAME_BONUS} ${LIBFT}
${NAME}: 		
				cc ${SRCS} ${LIBFT} -g3 -o ${NAME}
				@echo "$(NAME): $(NAME) was compiled."
				@echo

${NAME_BONUS}: 		
				${CC} ${BONUS_SRC} ${LIBFT} -L./lib/minilibx-linux ${MLX} ${MINILIBX_FLAGS} -g3 -o ${NAME_BONUS}
				@echo "$(NAME_BONUS): $(NAME_BONUS) was compiled."
				@echo

${LIBFT}:
				@echo
				make bonus -C libft

clean:
				make clean -C libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				@echo "${NAME}: ${NAME} and ${NAME_BONUS} were deleted"
				@echo
push:
	git add .
	git commit -m "commit"
	git push

re:	fclean all

re_bonus:	fclean bonus

go:	re

run_bonus:	re_bonus


valgrind: re

.PHONY:			all clean fclean re rebonus valgrind run run_bonus makefile
