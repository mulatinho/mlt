# MLT Mulato Layer Test

A extreme KISS (Keep It Simple Stupid) solution to test your software in C/C++

If you like, please follow and share. Thanks for using Mulato Layer Test. 

# How to integrate with your code

You just need to put the header "mlt.h" and use our functions to test software.

Here are some examples:

	tests/example1.c:	mlt_assert(x == 1);
	tests/example1.c:	mlt_assert(z == 42);
	tests/example1.c:	mlt_strneq(strone,"yourp4ssw0rd");
	tests/example1.c:	mlt_streq(strtwo,"yourp4ssw0rd");
	tests/example1.c:	mlt_finish();
	tests/example1.c:	return mlt_result;
	tests/example2.c:	mlt_assert(!unit_series_tests());
	tests/example2.c:	mlt_finish();
	tests/example2.c:	return mlt_result;

# build examples
$ make

# execute tests
$ make test

	:. executing 'tests/example1'...
	return success in 'tests/example1.c' on function 'main()' line 10, test 'x == 1'
	return success in 'tests/example1.c' on function 'main()' line 11, test 'z == 42'
	return success in 'tests/example1.c' on function 'main()' line 12, test 'strncmp(strone, "yourp4ssw0rd", strlen(strone))'
	return success in 'tests/example1.c' on function 'main()' line 13, test 'strncmp(strtwo, "yourp4ssw0rd", strlen(strtwo)) == 0'
	
	Result: PASSED, Filename: 'tests/example1.c'
	Tests run: 4, Tests PASSED: 4, Tests FAILED: 0
	
	:. executing 'tests/example2'...
	return success in 'tests/example2.c' on function 'main()' line 25, test '!unit_series_tests()'
	
	Result: PASSED, Filename: 'tests/example2.c'
	Tests run: 1, Tests PASSED: 1, Tests FAILED: 0
