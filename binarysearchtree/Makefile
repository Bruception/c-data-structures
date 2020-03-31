CC = gcc
OBJS = bst.o testbst.o
HDRS = bst.h

CFLAGS = -Wall

bst.out : $(OBJS)
	$(CC) $(CFLAGS) -o bst.out $(OBJS)

bst.o : bst.c
	$(CC) $(CFLAGS) -c bst.c

testbst.o : testbst.c
	$(CC) $(CFLAGS) -c testbst.c

$(OBJS) : $(HDRS)

clean:
	rm *.o bst.out