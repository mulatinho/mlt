# MLT (Mulato Layer Test)

A extreme KISS (Keep It Simple Stupid) solution to test your software in C/C++ with one header.

If you like, please follow and share. Thanks for using Mulato Layer Test. 

# How to integrate with your code

You just need to put the header "mlt.h" and use our functions to test software.

	$ git clone https://github.com/mulatinho/mlt
	$ vim yourtestfile.c 							# add include "mlt.h"
	$ gcc -I $PWD/mlt/ -o yourtestfile yourtestfile.c && ./yourtestfile

# Some examples

	tests/example1.c:	mlt_assert(x == 1);
	tests/example1.c:	mlt_assert(z == 42);
	tests/example1.c:	mlt_strneq(strone,"yourp4ssw0rd");
	tests/example1.c:	mlt_streq(strtwo,"yourp4ssw0rd");
	tests/example2.c:	mlt_assert(unit_series_tests() == 0);

# build and execute examples

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
