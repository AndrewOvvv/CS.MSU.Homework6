GCC=gcc
NSM=nasm
SRC=./source/
FLAGS=-m32 -Wall -pedantic -Wextra -Werror -I ./headers -lm

.PHONY: test clean

all: get_values root integral get_area test_bin

get_values: $(SRC)get_values.asm
	$(NSM) -f elf $(SRC)get_values.asm
	mv $(SRC)get_values.o .

root: $(SRC)root.c
	$(GCC) $(FLAGS) -c $(SRC)root.c

integral: $(SRC)integral.c
	$(GCC) $(FLAGS) -c $(SRC)integral.c

get_area: $(SRC)get_area.c
	$(GCC) $(FLAGS) -c $(SRC)get_area.c

test_bin: test.c
	$(GCC) $(FLAGS) test.c *.o -o test_bin

test: all
	./test_bin

clean:
	rm -f *.o test_bin