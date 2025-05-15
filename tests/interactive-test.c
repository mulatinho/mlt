#include "mlt.h"
#include <unistd.h>
#include <stdlib.h>

int random_int(int n)
{
	int res = 0;

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		res += (rand() % 30);
		usleep(500);
	}

	return res;
}

int main(int argc, char **argv)
{
	int n = 0, res = 0;
	char str[1024];

	if (argc < 2) {
		fprintf(stderr, "%s <iterations>\n", argv[0]);
		return 1;
	}

	mlt_start();
	mlt_suite_begin("interactive-test");

	n = atoi(argv[1]);
	res = random_int(n);

	fprintf(stdout, "str: ");
	fgets(str, sizeof(str)-1, stdin);
	str[strlen(str)-1] = '\0';

	fprintf(stdout, "\ninput-> res: '%d', str: '%s'\n", res, str);

	mlt_assert(res < 360);
	mlt_streq(str, "hello");

	mlt_suite_end();
	mlt_finish();

	return 0;
}

