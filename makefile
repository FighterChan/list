EXE = mac.elf

OBJ = main.o list_sort.o
SRC = main.c list_sort.c

$(EXE) : $(OBJ)
	gcc -o  $(EXE) $^

%.o:%.c
	gcc -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o *.elf
