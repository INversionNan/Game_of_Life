
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/game

SRC= main.c game.c initial.c save.c sdl.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
LIBS =   -lSDL2 -lSDL2_image

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c main.h game.h
game.o:  game.c main.h game.h
save.o:  save.c main.h
initial.o:  initial.c main.h
sdl.o: sdl.c main.h game.h