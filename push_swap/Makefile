NAME			= push_swap
CHECK			= checker
CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra -g
VALGRIND		= @valgrind --leak-check=full
REMOVE 			= rm -rf

SRCS 			= final_main/main_utils1.c final_main/main_utils2.c \
					final_main/main_utils3.c final_main/push_swap.c \
					final_main/sort_under_five.c \
					final_main/sort_utils.c \
					get_input/input_errors.c get_input/input_handle.c \
					ops/ops1.c ops/ops2.c ops/ops3.c ops/utils.c \
					push_chunk_b/push_utils.c push_chunk_b/to_b.c

CHECK_SRCS		= checker_bonus/checker_utils.c \
					checker_bonus/checker.c

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all

OBJS			= final_main/main_utils1.o final_main/main_utils2.o \
					final_main/main_utils3.o final_main/push_swap.o \
					final_main/sort_under_five.o \
					final_main/sort_utils.o \
					get_input/input_errors.o get_input/input_handle.o \
					ops/ops1.o ops/ops2.o ops/ops3.o ops/utils.o \
					push_chunk_b/push_utils.o push_chunk_b/to_b.o

CHECK_OBJS		= checker_bonus/checker_utils.o \
					checker_bonus/checker.o

LIBFT			= libft.a
GREEN			= \033[0;32m
RED				= \033[0;31m
RESET_COLOUR	= \033[0m

all:		$(LIBFT) ${NAME}

bonus:		$(LIBFT) ${CHECK}

${CHECK}: ${CHECK_OBJS} $(filter-out final_main/push_swap.o, ${OBJS})
	@${CC} ${CFLAGS} ${CHECK_OBJS} $(filter-out final_main/push_swap.o, ${OBJS}) ./libft/libft.a -o ${CHECK}

$(LIBFT):
	@echo "=== Starting Build ==="
	@make -C libft
${NAME}: ${OBJS}
	@${CC} ${OBJS} -L./libft -lft -o ${NAME}
clean:
	@$(REMOVE) $(OBJS) $(CHECK_OBJS)
fclean: clean
	@${REMOVE} ${NAME} ${CHECK}
re:	fclean all

go: all bonus
	./push_swap 9 8 7 6 5

valgrind_check: all bonus
	$(VALGRIND) ./push_swap "9 8 7 6 5 4 3 2 a" | ./checker "9 8 7 6 5 4 3 2 a"

go_checker: all bonus
	@clear
	@RESULT=$$(./push_swap 100 99 88 77 19 28361 273 18 | ./checker 100 99 88 77 19 28361 273 18); \
	if [ "$$RESULT" = "OK" ]; then \
	    echo "$(GREEN)Test 1: OK$(GREEN)$(RESET_COLOUR)"; \
	elif [ "$$RESULT" = "Error" ]; then \
	    echo "$(RED)Test 1: Error$(RED)$(RESET_COLOUR)"; \
	else \
	    echo "$(RED)Test 1: KO$(RED)$(RESET_COLOUR)"; \
	fi

limit_test: all bonus 
	@echo "${GREEN}worst case scenario in 100 numbers = ${GREEN}$(RESET_COLOUR)"
	@ARG=`seq 100 -1 1 | tr '\n' ' '`; ./push_swap $$ARG | wc -l
	@echo "${GREEN}worst case scenario in 700 numbers = ${GREEN}${RESET_COLOUR}"
	@ARG=`seq 500 -1 1 | tr '\n' ' '`; ./push_swap $$ARG | wc -l

challange_tests: limit_test all bonus
	# Test 1
	@ARG="4 8 3 9 7 6"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 2
	@ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 3
	@ARG="10 9 8 7 6 5 4 3 2 1"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 4
	@ARG="3 2 1"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 5
	@ARG="5 1 2 4 3"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 6
	@ARG="100 200 300 400 500"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 7
	@ARG="50 40 30 20 10"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 8
	@ARG="1 2 3 4 5 6 7 8 9 10"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 9
	@ARG="10 20 30 40 50 60 70 80 90 100"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 10
	@ARG="100 90 80 70 60 50 40 30 20 10"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 11
	@ARG="1 3 2 4 6 5 7 9 8 10"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 12
	@ARG="10 8 6 4 2 1 3 5 7 9"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 13
	@ARG="5 10 15 20 25 30 35 40 45 50"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 14
	@ARG="50 45 40 35 30 25 20 15 10 5"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 15
	@ARG="1 4 2 5 3 6 7 9 8 10"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 16
	@ARG="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 17
	@ARG="20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 18
	@ARG="1 3 5 7 9 2 4 6 8 10"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 19
	@ARG="10 9 8 7 6 5 4 3 2 1 11 12 13 14 15 16 17 18 19 20"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 20
	@ARG="20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 21
	@ARG="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 22
	@ARG="25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 23
	@ARG="1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 24
	@ARG="20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 21 22 23 24 25"; ./push_swap $$ARG | ./checker_linux $$ARG
	# Test 25
	@ARG="25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1"; ./push_swap $$ARG | ./checker_linux $$ARG

go_for_all: go_checker limit_test

error_tests: all bonus
	# Error Test 1: Non-numeric input
	@ARG="4 8 3 9 a"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 2: Duplicate numbers
	@ARG="1 5 2 4 3 2"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 3: Empty input - nothing should happen, no Error message according to the subject
	@ARG=""; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 4: Single non-numeric input
	@ARG="a"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 5: Mixed valid and invalid inputs
	@ARG="5 1 2 4 b"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 6: Exceeding integer limits
	@ARG="10000000000 200 300 400 500"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 7: Negative number exceeding limits
	@ARG="-2147483649 40 30 20 10"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 8: Multiple non-numeric inputs
	@ARG="1 2 3 4 5 6 7 8 9 10 a b c"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 9: Special characters
	@ARG="10 20 30 40 50 60 70 80 90 100 ! @ #"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 10: Only special characters
	@ARG="! @ # $ % ^ & *"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 11: Mixed valid and special characters
	@ARG="1 3 2 4 6 5 7 9 8 10 !"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 12: Leading zeros
	@ARG="5.5 10.1 15.2 20.3 25.4"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 13: Mixed integers and floating points
	@ARG="50 45.5 40 35.3 30 25.2 20 15.1 10 5"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true
	# Error Test 14: Mixed valid and invalid formats
	@ARG="1 4 2 5 3 6 7 9 8 10.5"; ./push_swap $$ARG || true | ./checker_linux $$ARG || true

.PHONY:	all bonus clean fclean re go valgrind_check go_checker limit_test challange_tests go_for_all error_tests makefile
