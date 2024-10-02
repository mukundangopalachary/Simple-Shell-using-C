CC = gcc
CFLAGS = -Wall
OBJS = src/shell.c src/commands.c src/redirection.c src/pipes.c src/utils.c

all: shell

shell: $(OBJS)
	$(CC) $(CFLAGS) -o shell $(OBJS)

clean:
	rm -f shell
