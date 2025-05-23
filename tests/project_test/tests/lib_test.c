#include "config.h"
#include "mlt.h"

int main(void)
{
	printf("I started the test_main() fn!\n");
	mlt_start();
	printf("I started the test_main() fn!\n");
	mlt_suite_begin("lib test");
	printf("I started the test_main() fn!\n");
	
	mlt_assert(return_number_of_life() == 42);
	mlt_assert(sum_two_numbers(2, 3) == 5);
	printf("I started the test_main() fn!\n");
	
	mlt_suite_end();
	mlt_finish();
	printf("I started the test_main() fn!\n");

	exit(0);
}
