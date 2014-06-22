CC     = gcc
OBJS   = main.o num.o
CFLAGS = -Wall

main:  $(OBJS)
	$(CC) -o $@ $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $<
