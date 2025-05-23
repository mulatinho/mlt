CC = gcc
CFLAGS = -Wall -Wextra -I./include -I./../../ -g -ggdb
TEST_CFLAGS = -DMLT_TESTING=1

MAIN_SRCS = $(wildcard src/*.c)
TEST_SRCS = $(wildcard tests/*.c)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

all: main lib_test

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main: $(MAIN_OBJS)
	$(CC) $^ -o src/$@

lib_test: $(MAIN_SRCS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_CFLAGS) $^ -o tests/$@

clean:
	rm -f $(MAIN_OBJS) $(TEST_OBJS) src/main tests/lib_test
