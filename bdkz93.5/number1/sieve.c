#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define functions
void SetBit(unsigned int A[], int K, int L);
int TestBit(unsigned int A[], int K, int L);
void PrintBit(unsigned int arr[], int arrayindex);
void SieveBit(unsigned int arr[]);
void printConverted(unsigned int arr[], int arrayIndex);
//main
int main(){
	
	const int size = ceil(100000 / (sizeof(unsigned int) * 8));
	unsigned int array[size];	
	int i;
	int count;
	//Initializes bit vector
	for(i = 0; i < size; i++)
	{
		array[i] = 0;
	}
	//Calls functions to perform sieve
	SieveBit(array);
	PrintBit(array, 5);
	printConverted(array, size);

return 0;
}
//Sets the bit a value. Utilized in SieveBit
void SetBit(unsigned int A[], int K, int L)
{
	int i = K;
	int pos = L;

	unsigned int flag = 1;

	flag = flag << pos;

	A[i] = A[i] | flag;
	return;
}
//Check bit for 0 or 1. Utilized in SieveBit
int TestBit(unsigned int A[], int K, int L)
{
	
	unsigned int flag = 1;
	
	flag = flag << L;

	if (A[K] & flag)
	{	
		return 1;
	}
	else
	{
		return 0;
	}
}
//Prints it. good for me to test
void PrintBit(unsigned int arr[], int arrayindex)
{
	int i;
	int j;
	unsigned int flag;
	for(i = arrayindex; i >= 0; --i)
	{
		for(j = sizeof(int) * 8 - 1; j >= 0; --j)
		{
			flag = 1;
			flag = flag << j;

			if(arr[i] & flag)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
			if(j == 0)
				printf("\t%d\n", i);
		}
	}
	return;
}
//Actual sieve math operations on bit vectors
void SieveBit(unsigned int arr[])
{
	int i;
	int j = 0;
	int x = 0;

	for(i = 2; i <= (int)sqrt(100000); ++i)
	{
		if(TestBit(arr, i / 32, i % 32) == 0)
		{
			x = 0;
			j = 0;
			while(j <= 100000)
			{
				if((i * i) + (x * i) <= 100000)
				{
					j = (i * i) + (x * i);
					SetBit(arr, j / 32, j % 32);
					++x;
				}
				else
				{
					j = 100001;
				}
			}
		}
		
	}
	return;
}
//Prints it in proper format with numbers and such
void printConverted(unsigned int arr[], int arrayIndex)
{
	int i;
	int j;
	
	for(i = 0; i < 100000; ++i)
	{
		if(TestBit(arr, i / 32, i % 32) == 0)
		{
			printf("%d is prime. \n", i);
		}
	}
	return;
}
