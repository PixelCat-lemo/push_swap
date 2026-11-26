CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap

FTPRINT_DIR = ./ft_printf
FTPRINT = $(FTPRINT_DIR)/libftprintf.a
INCLUDES = -I. -I$(FTPRINT_DIR)

SRCS = 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINT)
	ar rcs $(NAME) $(OBJS) $(FTPRINT)

$(FTPRINT):
	$(MAKE) -C $(FTPRINT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FTPRINT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re