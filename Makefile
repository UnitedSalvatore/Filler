NAME = resources/players/ypikul.filler

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = main.c 

SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./libft/include/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) -o $@ $(FLAGS) $^

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

one: all
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/ypikul.filler -p2 resources/players/champely.filler

two: all 
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/champely.filler -p2 /resources/players/ypikul.filler

.PHONY: all clean fclean re one two
