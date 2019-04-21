#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

hrtime_t gethrtime(void);

int FibRecursive(int x);
int FibIterative(int x);
//Main
int main()
{
int input = 0;
printf("please enter a number for fib.");
scanf("%d", input);

printf("%d", FibIterative(input));
//printf("%d", FibRecursive(input));


return 0;
}
int FibRecursive(int x)
{
	if (x == 0)
	{
		return 0;
	}
	if (x == 1)
	{
		return 1;
	}

	return FibRecursive(x-1) + FibRecursive(x-2);
}

int FibIterative(int x)
{
	int temp = 0;
	int arr[2] = {0,1};
	int i = 0;
	while (i < x)
	{
		temp = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = temp;
		i++;
	}
	
	return arr[0];
}

