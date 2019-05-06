#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<klee/klee.h>


void isSorted( int * arr, int len)
{	
	for(int i = 0; i<len-1; i++)
	{
		if (arr[i+1] <arr[i])
		{
			//printf("There is a problem with sorting!\n"); 
			klee_assert(0);
		}
	}
	printf("Sorting is OK!\n"); 
}

int isInside(int *arr, int x, int len)
{
	for (int i = 0 ; i<len ;i++)
	{
		if (arr[i] == x)
		{
			return 1;
		}
	}
	return 0;
}



void isPermotation(int * original, int * copy , int len)
{
	int i;

	//checing if all elemnts from the original array are in the sorted array
	for (i =0; i<len; i++)
	{
		if (!isInside(copy, original[i], len))
		{
			printf("There is a problem with permutation\n"); 
			klee_assert(0);
		}
	}
	printf("Permutation is OK!\n"); 
}
			
	
	
	

int main()
{
	int i, j, a;
	// array length
	int n = 3;
	int number[n];
	
	// make the array to be sorted as symbolyic
	klee_make_symbolic(number, n*sizeof(int), "number");
	
	int* orig_number = malloc(n*sizeof(int));
	
	// save the original input array
	for (i = 0; i< n; i++)
	{
		orig_number[i] = number[i];
	}

	// bubble sort algo
	for (i = 0; i < n; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (number[i] > number[j])
			{
				a =  number[i]; 
				number[i] = number[j];
				number[j] = a;
			}
		}
	}

	
	
	// Klee Assertions 
	isPermotation(orig_number, number, n);
	isSorted(number,n);
	printf("END OF RUNNING\n");
	
	return 0;
}
