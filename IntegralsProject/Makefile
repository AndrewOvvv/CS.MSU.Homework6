GCC=gcc
NSM=nasm
SRC=./source/
FLAGS=-m32 -Wall -pedantic -Wextra -Werror -I ./headers -lm

.PHONY: test clean

all: get_values root integral get_area task6

get_values: $(SRC)get_values.asm
	$(NSM) -f elf $(SRC)get_values.asm
	mv $(SRC)get_values.o .

root: $(SRC)root.c
	$(GCC) $(FLAGS) -c $(SRC)root.c

integral: $(SRC)integral.c
	$(GCC) $(FLAGS) -c $(SRC)integral.c

get_area: $(SRC)get_area.c
	$(GCC) $(FLAGS) -c $(SRC)get_area.c

task6: test.c
	$(GCC) $(FLAGS) test.c *.o -o task6

test: all
	./task6

flag_test: all
	./task6 -test -pprf -pcif

clean:
	rm -f *.o task6