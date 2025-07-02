CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lm

OBJS = main.o linear_algebra.o

app: $(OBJS)
	$(CC) $(OBJS) -o app $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o app

