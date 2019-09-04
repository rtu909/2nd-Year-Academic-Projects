CFLAGS=-pg -g -O2 -Wall
CC=gcc
LDFLAGS=-pg

PROGRAM_NAME= evolve
OBJS = main.o readwriteppm.o fitness.o population.o evolve.o \
	crossover.o mutate.o

$(PROGRAM_NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $? -lm

escher:
	make; make
	./evolve me.ppm me2.ppm 50000 24 3e-2
mcmaster:
	make; make
	./evolve mcmaster.ppm mcmaster2.ppm 40000 500 3e-2 

clean:
	rm  *.o $(PROGRAM_NAME) *~S
