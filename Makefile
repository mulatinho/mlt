CFLAGS = -I ./ -W -Wall -O2
TESTS = tests/example1 tests/example2

all: $(TESTS)

test:
	@for test in $(TESTS); do echo "\033[1m:. executing '$$test'...\033[m"; ./$$test; done

clean:
	rm -fv $(TESTS)
