NAME = ypikul.filler

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = 

SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./libft/include/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS) $(LIBFT)
	ranlib $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)/

obj:
	mkdir obj/

obj/%.o: ./%.c | obj
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf obj/
	make -C $(LIBFT_DIR)/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
