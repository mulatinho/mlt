#include "massert.h"

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
	mlt_assert(!unit_series_tests());

	mlt_finish();

	return mlt_result;
}
