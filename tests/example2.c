#define DEBUG 1
#include "mlt.h"

int unit1(void) 
{
	return 0;
}

int unit2(int a)
{
	return a == 42 ? 0 : 1;
}

int unit_series_tests()
{
	int ret = 0;

	if (!ret) { ret = unit1(); }
	if (!ret) { ret = unit2(42); }

	return ret;
}

int main(void)
{
	mlt_start();

	mlt_assert(unit_series_tests() == 0);

	mlt_finish();

	return mlt_result;
}
