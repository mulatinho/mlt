#include "config.h"
#include "mlt.h"

int main(void) 
{
	regex_t regex;
	mlt_start();

	mlt_suite_begin("Basic Assertions");
	mlt_assert(return_number_of_life() == 42);
	mlt_assert(sum_two_numbers(2, 3) == 5);
	mlt_suite_end();

	mlt_suite_begin("String Utilities");
	char foo[] = "foo";
	char bar[] = "foobar";
	mlt_streq(foo, "foo");
	mlt_strneq(foo, "bar");
	mlt_strupper(foo);
	mlt_assert(strcmp(foo, "FOO") == 0);
	mlt_strlower(foo);
	mlt_assert(strcmp(foo, "foo") == 0);
	mlt_assert(mlt_strcontains(bar, "oba") == 1);
	mlt_suite_end();

	mlt_suite_begin("Array Utilities");
	int arr[] = {3, 1, 4, 1, 5};
	size_t n = mlt_arr_len(arr);
	mlt_debug("Array length: %zu\n", n);
	mlt_print_int_arr(arr, n);
	mlt_suite_end();

	mlt_suite_begin("Regex Utilities");
	mlt_regex_compile("foo.*", &regex);
	mlt_assert(mlt_regex_exec(&regex, "foobar") == 0);
	mlt_regex_free(&regex);
	mlt_suite_end();

	mlt_suite_begin("Timing Example");
	mlt_time_init();
	usleep(10000);
	struct timeval end;
	gettimeofday(&end, NULL);
	double elapsed = mlt_time_calc(end, mlt_subinit_t);
	mlt_debug("Elapsed: %.6f seconds\n", elapsed);
	mlt_suite_end();

	mlt_finish();

	return 0;
}
