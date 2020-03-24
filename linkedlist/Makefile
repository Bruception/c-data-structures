CC = gcc
OBJS = linkedlist.o testlinkedlist.o
HDRS = linkedlist.h

CFLAGS = -Wall

linkedlist.out : $(OBJS)
	$(CC) $(CFLAGS) -o linkedlist.out $(OBJS)

linkedlist.o : linkedlist.c
	$(CC) $(CFLAGS) -c linkedlist.c

testlinkedlist.o : testlinkedlist.c
	$(CC) $(CFLAGS) -c testlinkedlist.c

$(OBJS) : $(HDRS)

clean:
	rm *.o linkedlist.out