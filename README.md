# MLT (Mulato Layer Test)

A extreme KISS (Keep It Simple Stupid) solution to test your software in C/C++ with one header.

If you like, please follow and share. Thanks for using Mulato Layer Test. 

# How to integrate with your code

You just need to put the header "mlt.h" and use our functions to test software. Here is an example using the [latency-test](github.com/mulatinho/latency-test) software

	$ mkdir tests && cd tests && git clone https://github.com/mulatinho/mlt
	$ vim latency-test_test.c 							# add include "mlt.h"

## Makefile
Manual compile like the commands below or just add a target in your Makefile
```sh
test:
	gcc -DMLT_TESTING=1 -Wall -g -ggdb -o src/latency-test.o -c src/latency-test.c ${CARGS} -I./tests/mlt
	gcc -DMLT_TESTING=1 -Wall -g -ggdb -o tests/latency-test_test.o -c tests/latency-test_test.c ${CARGS} -I./tests/mlt
	gcc -DMLT_TESTING=1 -Wall -g -ggdb -o tests/latency-test_test src/latency-test.o tests/latency-test_test.o ${CARGS} -I./tests/mlt
```

## latency-test_test.c

```c
#include "mlt.h"
#include "../src/latency-test.h"

void unit_test_get_ip(void)
{
        int BATTERY_INPUT = 0, BATTERY_OUTPUT = 1;
        char *battery_test[][NAME_MAX] = {
                { "localhost", "127.0.0.1" },
                { "127.0.0.1", "127.0.0.1" },
                { "dns.google", "8.8.8.8" },
        };
        int battery_size = sizeof(battery_test) / sizeof(battery_test[0]);

        for (int battery = 0; battery < battery_size; battery++) {
                char *result = latency_host_to_ip(battery_test[battery][BATTERY_INPUT]);
                mlt_assert(result != NULL);
                mlt_streq(result, battery_test[battery][BATTERY_OUTPUT]);
        }

        mlt_assert(latency_host_to_ip("sdadi.dwsf") == NULL);
}

int main(void)
{
    mlt_start();
    unit_test_get_ip();
    mlt_finish();
}

```

## main.c

add the macro `#ifndef MLT_TESTING` on your main function so when you compile your tests it will not call your main but rather the tests main.
```c
#include <stdio.h>

#ifndef MLT_TESTING
int main(int argc, char **argv) {
	return 0;
}
#endif
```

## output

```sh
$ make test && ./tests/latency-test_test 
:. Started test(s) on 'tests/latency-test_test.c' at Mon May 12 12:11:32 2025

return success in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 27,
test 'result != ((void *)0)'
return success in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 28,
test 'strncmp(result, battery_test[battery][BATTERY_OUTPUT], strlen(result)) == 0'
return success in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 27,
test 'result != ((void *)0)'
return success in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 28,
test 'strncmp(result, battery_test[battery][BATTERY_OUTPUT], strlen(result)) == 0'
return success in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 27,
test 'result != ((void *)0)'
return error   in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 28,
test 'strncmp(result, battery_test[battery][BATTERY_OUTPUT], strlen(result)) == 0'
return success in 'tests/latency-test_test.c' on function 'unit_test_get_ip()' line 31,
test 'latency_host_to_ip("sdadi.dwsf") == ((void *)0)'

:. Result: FAILED, Time Elapsed: 0.213ms, Filename: 'tests/latency-test_test.c'
:. Tests run: 7, Tests PASSED: 6, Tests FAILED: 1
```

# Types of Test

	- Simple instruction test,
	- Time execution test,
	- Input/Output comparision test,
	- Interactive test.

# Function assertion examples

	tests/example1.c:	mlt_assert(x == 1);
	tests/example1.c:	mlt_assert(z == 42);
	tests/example1.c:	mlt_strneq(strone,"yourp4ssw0rd");
	tests/example1.c:	mlt_streq(strtwo,"yourp4ssw0rd");
	tests/example2.c:	mlt_assert(unit_series_tests() == 0);

## Build and execute examples

	$ make && make test

	:. Started test(s) on 'tests/example1.c' at Wed Jun 28 22:36:12 2017
	return success in 'tests/example1.c' on function 'main()' line 13, test 'x == 1'
	return success in 'tests/example1.c' on function 'main()' line 14, test 'z == 42'
	return success in 'tests/example1.c' on function 'main()' line 15, test 'strncmp(strone, "yourp4ssw0rd", strlen(strone))'
	return success in 'tests/example1.c' on function 'main()' line 16, test 'strncmp(strtwo, "yourp4ssw0rd", strlen(strtwo)) == 0'
	
	:. Result: PASSED, Time Elapsed: 0.001ms, Filename: 'tests/example1.c'
	:. Tests run: 4, Tests PASSED: 4, Tests FAILED: 0
	
	:. Started test(s) on 'tests/example2.c' at Wed Jun 28 22:36:12 2017
	return success in 'tests/example2.c' on function 'main()' line 28, test 'unit_series_tests() == 0'
	
	:. Result: PASSED, Time Elapsed: 0.001ms, Filename: 'tests/example2.c'
	:. Tests run: 1, Tests PASSED: 1, Tests FAILED: 0
	
	spawn ./tests/interactive-test 2 ehlo
	:. Started test(s) on 'tests/interactive-test.c' at Wed Jun 28 22:36:12 2017
	  elapsed time in 'tests/interactive-test.c' on function 'random_int()', time: 0.001ms
	str: hello
	res: 14, str: 'hello'
	return success in 'tests/interactive-test.c' on function 'main()' line 42, test 'res < 50'
	return success in 'tests/interactive-test.c' on function 'main()' line 43, test 'strncmp(str, "hello", strlen(str)) == 0'
	
	:. Result: PASSED, Time Elapsed: 0.002ms, Filename: 'tests/interactive-test.c'
	:. Tests run: 2, Tests PASSED: 2, Tests FAILED: 0
	
	result: succcess, 'tests/inout-powertest.out' and 'tests/inout-powertest.chk' are equals
