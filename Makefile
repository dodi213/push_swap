NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
			  parser.c \
			  parser_utils.c \
			  parser_validation.c \
			  ft_utils.c \
			  smaller_init.c \
			  disorder.c \
			  swap.c \
			  push.c \
			  rot.c \
			  revrot.c \
			  ft_selection.c \
			  ft_bucket.c \
			  ft_radix.c \
			  special_case.c \
			  bench.c \
			  bench_utils.c

OBJS		= $(SRCS:.c=.o)

HEADER		= push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
