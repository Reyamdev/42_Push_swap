NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SRCS =	src/main.c \
		src/stack/stack.c \
		src/parsing/parse.c \
		src/parsing/parse_value.c \
		src/algorithms/disorder.c \
		src/algorithms/sort_utils.c \
		src/algorithms/simple_sort.c \
		src/algorithms/medium_sort.c \
		src/algorithms/complex_sort.c \
		src/algorithms/adaptive_sort.c \
		src/bench/bench_stats.c \
		src/bench/bench_print.c \
		src/operations/swap.c \
		src/operations/push.c \
		src/operations/rotate.c \
		src/operations/rotate_back.c

BONUS_SRCS =	bonus/checker_bonus.c \
				bonus/instruction_bonus.c \
				bonus/instructions.c \
				bonus/read_instruction_bonus.c \
				bonus/read_instruction_utils_bonus.c

SHARED_SRCS =	src/stack/stack.c \
				src/parsing/parse_value.c \
				src/algorithms/sort_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o) $(SHARED_SRCS:.c=.o)

HEADERS = push_swap.h bonus/checker_bonus.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

bonus: $(BONUS_NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
