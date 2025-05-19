CC=gcc
HEADERS=-I./
WARNINGS=-W -Wno-implicit-function-declaration
SRC=$(wildcard tests/*.c)
CFLAGS=$(WARNINGS) -O2 -ansi -std=c99 $(HEADERS)
LDLIBS=-lm
TESTS=tests/example1 tests/example2 tests/suite
ITESTS=tests/interactive-test
DTESTS=tests/inout-powertest

all: $(TESTS) $(ITESTS) $(DTESTS)

clean:
	@rm -fv $(TESTS) $(ITESTS) $(DTESTS) 
	@rm -fv tests/*.out
	@rm -fv tests/*.log
	@rm -rfv tests/*dSYM

rebuild: clean all

test:
	@for test in $(TESTS); do \
		./$$test | tee -a $$test.log; \
	done
	@for test in $(ITESTS); do \
		./$$test.exp 12 hello | tee -a $$test.log; \
	done
	@for test in $(DTESTS); do \
		(./$$test < $$test.in | grep -v 'Starting test' > $$test.out && \
			diff -q $$test.out $$test.chk && \
			echo "result: succcess, '$$test.out' and '$$test.chk' are equals" || \
			echo "result: fail,     '$$test.out' and '$$test.chk' are different.") | tee -a $$test.log; \
	done

format:
	clang-format --verbose -i $(SRC)

lint:
	clang-tidy $(SRC) -- -std=c99 $(HEADERS) $(WARNINGS)

install:
	install -m 0644 mlt.h /usr/local/include/
	install -m 0644 doc/mlt.1 /usr/local/share/man/man1/

uninstall:
	rm -fv /usr/local/include/mlt.h
	rm -fv /usr/local/share/man/man1/mlt.1
