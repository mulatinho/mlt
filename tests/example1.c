#include "mlt.h"

int main(void)
{
	int x, z;
	char strone[] = "hello world";
	char strtwo[] = "yourp4ssw0rd";

	mlt_start();

	x = 1; z = 42;
	mlt_assert(x == 1);
	mlt_assert(z == 42);
	mlt_strneq(strone,"yourp4ssw0rd");
	mlt_streq(strtwo,"yourp4ssw0rd");

	mlt_debug("hey jack");
	mlt_finish();

	return mlt_result;
}
