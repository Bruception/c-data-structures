CC = gcc
OBJS = stack.o teststack.o
HDRS = stack.h

CFLAGS = -Wall

stack.out : $(OBJS)
	$(CC) $(CFLAGS) -o stack.out $(OBJS)

stack.o : stack.c
	$(CC) $(CFLAGS) -c stack.c

teststack.o : teststack.c
	$(CC) $(CFLAGS) -c teststack.c

$(OBJS) : $(HDRS)

clean:
	rm *.o stack.out