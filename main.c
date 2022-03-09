#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float function(float x)
{
	return (float) (pow(x, 3) - 12 * x + 10);
}

char lower_or_greater(float x)
{
	return 0*(function(x) > 0) + 1*(function(x) < 0);
}

float simple_round(float x, int e)
{
	return round(x*pow(10, e))/pow(10, e);
}

int howm(float e)
{

	int count;
	float var = e;

	for(count = 1; var != (float)1; count++)
	{
		var=simple_round(var, 2)+e;
		printf("%f\n", var);	
	}

	return count;
}

int main()
{

	float range[2];
	int E;
	float result;

	char str[100];

	printf("MIN: ");	
	gets(str);

	range[0] = atoi(str);

	printf("MAX: ");	
	gets(str);

	range[1] = atoi(str);

	printf("E: ");
	gets(str);

	E = atoi(str);


	//round(range[0]*100)/100 != round(range[1]*100)/100

	int i;
	for (i = 1; simple_round(range[0], E) < simple_round(range[1], E); ++i)
	{
		result = (float)((range[0]+range[1])/2);
		range[lower_or_greater(result)] = result;
		//printf("X%d = %.*f\n", i, E, result);
		//printf("X in [%f ; %f]\n", simple_round(range[0], E), simple_round(range[1], E));
		printf("\n");
	}

	printf("%d\n", i);
	printf("X%d = %.f\n", i, result);
	printf("X in [%f ; %f]\n", simple_round(range[0], E), simple_round(range[1], E));

	//printf("%f\n", simple_round(2.3492, 3));
	//printf("%d\n", howm(E));

	//int test = (*(int*)&E)-0x1A0C49B-0x1A0C49B;
	//printf("%d\n", test);
	//printf("%f\n", *(float*)&test);
	
	
	return 0;
}