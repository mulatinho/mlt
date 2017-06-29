CFLAGS = -I ./ -W -O2
TESTS = tests/example1 tests/example2
ITESTS = tests/interactive-test
DTESTS = tests/inout-powertest

all: $(TESTS) $(ITESTS) $(DTESTS)

test:
	@for test in $(TESTS); do \
		echo "\033[1m:. executing '$$test'...\033[m"; \
		./$$test | tee -a $$test.log; \
	done
	@for test in $(ITESTS); do \
		echo "\033[1m:. expecting '$$test.exp'...\033[m"; \
		./$$test.exp 2 hello | tee -a $$test.log; \
	done
	@for test in $(DTESTS); do \
		echo "\033[1m:. expecting '$$test.exp'...\033[m"; \
		(./$$test < $$test.in > $$test.out && \
			diff -q $$test.out $$test.chk && \
			echo "result: succcess, '$$test.out' and '$$test.chk' are equals" || \
			echo "result: fail,     '$$test.out' and '$$test.chk' are different.") | tee -a $$test.log; \
	done
	egrep '^:.' tests/*.log | sed -e 's@.*:\. @@g' > tests.log

clean:
	@rm -fv $(TESTS) $(ITESTS) $(DTESTS) tests/*.{out,log} tests.log 
	@rm -rfv tests/*dSYM
