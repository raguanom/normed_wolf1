NAME = test

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lSDL2 -o $(NAME) -I include/ -I include/SDL2/ -L ~/lib

CFILES = parse_map.c init_struct.c events.c main.c ray_cast.c render.c timing.c ./libft/libft.a

OBJ = $(CFILES:.c=.o)

$(NAME):
	gunzip -c SDL2-2.0.5.tar.gz | tar xf -
	cd SDL2-2.0.5; \
	mkdir build; \
	cd build; \
	../configure; \
	make
	mkdir -p ~/lib/
	cp SDL2-2.0.5/build/build/.libs/libSDL2-2.0.0.dylib ~/lib/
	ln -F -s ~/lib/libSDL2-2.0.0.dylib ~/lib/libSDL2.dylib
	mkdir -p include/SDL2
	cp SDL2-2.0.5/include/*.h include/SDL2/
	$(MAKE) -C libft all
	$(CC) $(CFILES) $(CFLAGS)
	
all: $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean:
	rm -rf $(NAME)
	rm -rf include/SDL2
	rm -rf SDL2-2.0.5
	$(MAKE) -C libft fclean

re: fclean all

run:
	$(CC) $(CFILES) $(CFLAGS)
	./$(NAME) map.wolf3d
