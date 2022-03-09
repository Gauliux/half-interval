#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float function(float x)
{
	return (float) (pow(x, 3) - 12 * x + 10);
}

float simple_round(float x, int e)
{
	return round(x*pow(10, e))/pow(10, e);
}

char direction(float a, float b)
{
	return 0*(function(a) < 0) + 1*(function(b) < 0);
}

char lower_or_greater(float x)
{
	return 0*(function(x) > 0) + 1*(function(x) < 0);
}

int main(int argc, char *argv[])
{

	float range[2];
	float E;

	range[0] = atoi(argv[1]);
	range[1] = atoi(argv[2]);
	E = atof(argv[3]);

	float result;
	int counter;

	for (counter = 1; fabs(range[1]-range[0]) > E; ++counter)
	{
		result = (float)((range[0]+range[1])/2);
		range[(direction(range[0], range[1])) ? lower_or_greater(result) : !lower_or_greater(result)] = result;

		printf("X%d = %f\n", counter, result);
		printf("F(x) = %f\n", function(result));
		printf("X in [%f ; %f]\n", range[0], range[1]);
		printf("\n");
	}

	printf("Steps: %d\n", counter);
	printf("X%d = %.2f\n", counter, result = (float)((range[0]+range[1])/2));

	//printf("%f\n", simple_round(2.3492, 3));
	//printf("%d\n", howm(E));

	//int test = (*(int*)&E)-0x1A0C49B-0x1A0C49B;
	//printf("%d\n", test);
	//printf("%f\n", *(float*)&test);

	return 0;
}