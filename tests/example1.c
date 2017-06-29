#define DEBUG 1
#include "mlt.h"

int main(void)
{
	int x, y, z;
	char strone[] = "hello world";
	char strtwo[] = "yourp4ssw0rd";

	mlt_start();

	x = 1; y = 10; z = 42;
	mlt_assert(x == 1);
	mlt_assert(z == 42);
	mlt_strneq(strone,"yourp4ssw0rd");
	mlt_streq(strtwo,"yourp4ssw0rd");

	mlt_finish();

	return mlt_result;
}
