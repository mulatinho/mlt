#include "mlt.h"
#include <math.h>


double calc(double number, double n) 
{
	double sum = 0.0;

	for (int x = 0; x < (int)n; x++) {
		sum += pow(number, x);
		printf("%.2f ", pow(number, x));
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
