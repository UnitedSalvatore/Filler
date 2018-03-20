NAME = ypikul.filler

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = main.c \
			parse.c \
			set_coordinates.c \
			crop_token.c

SOURCES = $(addprefix ./src/, $(FILENAMES))
OBJECTS = $(addprefix ./obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./

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
	rm -f filler.trace

fclean: clean
	rm -f $(NAME)

re: fclean all

one: all
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/ypikul.filler -p2 resources/players/superjeannot.filler

two: all
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 resources/players/ypikul.filler

ones: all
	./resources/filler_vm -f resources/maps/map03 -p1 resources/players/ypikul.filler -p2 resources/players/superjeannot.filler

twos: all
	./resources/filler_vm -f resources/maps/map03 -p1 resources/players/abanlin.filler -p2 resources/players/ypikul.filler

look: all
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 resources/players/superjeannot.filler

.PHONY: all clean fclean re one two ones twos
