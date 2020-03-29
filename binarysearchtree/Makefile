CC = gcc
OBJS = binarysearchtree.o testbst.o
HDRS = binarysearchtree.h

CFLAGS = -Wall

binarysearchtree.out : $(OBJS)
	$(CC) $(CFLAGS) -o binarysearchtree.out $(OBJS)

binarysearchtree.o : binarysearchtree.c
	$(CC) $(CFLAGS) -c binarysearchtree.c

testbst.o : testbst.c
	$(CC) $(CFLAGS) -c testbst.c

$(OBJS) : $(HDRS)

clean:
	rm *.o binarysearchtree.out