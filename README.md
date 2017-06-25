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
