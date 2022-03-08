
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char function(double x)
{
	double y = (pow(x, 3) - 12 * x + 10);
	
	return y;
}

char lower_or_greater(double x)
{
	return 0*(function(x) > 0) + 1*(function(x) < 0);
}

int main()
{
	
	double max = 1;
	double min = 0;
	
	double range[2] = {min, max};
	
	double result;
	double reserve;
	
	double a = max;
	double b = min;
	
	/*while()
	{
		
		result = (double)((a+b)/2);
		
	}*/
	
	printf("%d\n", lower_or_greater(-2));
	
	//f
	//lf
	printf("%.2f\n", function(-2));
	
	
	return 0;
}