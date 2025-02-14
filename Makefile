NAME = push_swap
SRCS = others/error_hundlers.c libft_functions/ft_memmove.c libft_functions/ft_split.c libft_functions/ft_strdup.c libft_functions/ft_strlen.c libft_functions/ft_substr.c \
		operations/operations2.c operations/operations3.c operations/operations.c \
		parsing/parsing_helpers2.c parsing/parsing_helpers.c mandatory/push_swap.c sorting/small_sort.c sorting/sort.c sorting/sort_helpers.c sorting/sort_utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
