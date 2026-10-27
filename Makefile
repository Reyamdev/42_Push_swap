NAME = push_swap

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

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
