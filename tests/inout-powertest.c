#include "mlt.h"
#include <math.h>

#define DEBUG 1

double calc(double number, double n) 
{
	double sum = 0.0;

	for (double x = 0.0; x < n; ++x) {
		sum += pow(number, x);
		printf("%.2f ", sum);
	}
	printf("\n");

	return sum;
}


int main(void)
{
	double number = 0, qt = 0;

	mlt_start();

	scanf("%lf", &number);
	scanf("%lf", &qt);

	printf("%.2f\n", calc(number, qt));

	mlt_finish();

	return 0;
}
