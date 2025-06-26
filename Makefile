CC = gcc
CFLAGS = -Wall -Wextra

OBJS = main.o linear_algebra.o

app: $(OBJS)
	$(CC) $(OBJS) -o app

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o app

