CC = gcc
CFLAGS = -std=c17 -Wall -Wextra
LDFLAGS = -lm

OBJS = main.o linalg.o

app: $(OBJS)
	$(CC) $(OBJS) -o app $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o app

