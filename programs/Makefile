CC = gcc
CFLAGS = -Wall -g

SRCS = $(wildcard *.c)
EXECS = $(SRCS:.c=.bin)

all: $(EXECS)

%.bin: %.c
	$(CC) $(CFLAGS) $< -o $@

clean: 
	rm *.bin