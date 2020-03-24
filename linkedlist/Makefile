CC = gcc
OBJS = linkedlist.o main.o
HDRS = linkedlist.h

CFLAGS = -Wall

linkedlist.out : $(OBJS)
	$(CC) $(CFLAGS) -o linkedlist.out $(OBJS)

linkedlist.o : linkedlist.c
	$(CC) $(CFLAGS) -c linkedlist.c

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

$(OBJS) : $(HDRS)

clean:
	rm *.o linkedlist.out